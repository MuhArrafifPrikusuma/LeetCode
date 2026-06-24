// # 1 two sum
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
typedef struct {
  int val;
  int index;
} LookUp;
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int hashSize = numsSize * 2;
  *returnSize = 2;

  LookUp *table = calloc(hashSize, sizeof(LookUp));
  int *result = malloc(*returnSize * sizeof(int));
  int *occupied = calloc(hashSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int missing = target - nums[i];
    int hashIndex = abs(missing) % hashSize;

    while (occupied[hashIndex]) {
      if (table[hashIndex].val == missing) {
        result[0] = table[hashIndex].index;
        result[1] = i;

        free(table);
        free(occupied);
        return result;
      }
      hashIndex = (hashIndex + 1) % hashSize;
    }
    int addIndex = abs(nums[i]) % hashSize;
    while (occupied[addIndex]) {
      addIndex = (addIndex + 1) % hashSize;
    }
    table[addIndex].val = nums[i];
    table[addIndex].index = i;
    occupied[addIndex] = 1;
  }

  free(table);
  free(occupied);
  *returnSize = 0;
  return NULL;
}

// # 2 add Two Numbers ( using linked list )
struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode dummy;
  dummy.val = 0;
  dummy.next = NULL;

  int carry = 0;

  struct ListNode *current = &dummy;
  while (l1 != NULL || l2 != NULL || carry != 0) {
    int val1 = (l1 != NULL) ? l1->val : 0;
    int val2 = (l2 != NULL) ? l2->val : 0;

    int sum = val1 + val2 + carry;
    carry = sum / 10;

    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = sum % 10;
    newNode->next = NULL;

    current->next = newNode;
    current = current->next;

    if (l1 != NULL)
      l1 = l1->next;
    if (l2 != NULL)
      l2 = l2->next;
  }
  struct ListNode *result = dummy.next;

  return result;
}

// # 3. Longest substring without repeating characters
int lengthOfLongestSubstring(char *s) {
  int seen[128] = {0};
  int longest = 0;
  int delete = 0;
  for (int add = 0; s[add] != '\0'; add++) {
    uint currentChar = s[add];
    while (seen[currentChar] > delete) {
      delete = seen[currentChar];
    }
    seen[currentChar] = add + 1;
    int currentWindow = add - delete + 1;
    if (currentWindow > longest) {
      longest = currentWindow;
    }
  }
  return longest;
}

// # 5 Longest Palindromic substring
int expand(char *string, int left, int right) {
  while (left >= 0 && string[right] != '\0' && string[left] == string[right]) {
    left--;
    right++;
  }
  return right - left - 1;
}

char *longestPalindrome(char *s) {
  int maxlen = 0;
  int len = strlen(s);
  int start = 0;

  for (int i = 0; i < len; i++) {
    int len1 = expand(s, i, i);
    int len2 = expand(s, i, i + 1);

    int currentLen = (len1 > len2) ? len1 : len2;
    if (currentLen > maxlen) {
      maxlen = currentLen;
      start = i - (maxlen - 1) / 2;
    }
  }
  s[start + maxlen] = '\0';

  return s + start;
}

// #6. Zigzag Conversion

char *convert(char *s, int numrows) {
  int len = strlen(s);
  if (numrows == 1 || numrows == len)
    return strdup(s);

  int jump = (2 * numrows) - 2;
  char *result = (char *)malloc((len + 1) * sizeof(char));
  int resultindex = 0;

  for (int i = 0; i < numrows; i++) {
    for (int j = 0; j + i < len; j += jump) {
      result[resultindex++] = s[j + i];

      if (i != 0 && i != numrows - 1) {
        int middleindex = j + jump - i;
        if (middleindex < len)
          result[resultindex++] = s[middleindex];
      }
    }
  }
  result[resultindex] = '\0';
  return result;
}

// #7 Reverse integer

int reverse(int x) {
  if (x >= INT_MAX || x <= INT_MIN || x == 0)
    return 0;
  long reverse = 0;

  while (x != 0) {

    reverse = (reverse * 10) + (x % 10);
    x /= 10;
  }
  if (reverse >= INT_MAX || reverse <= INT_MIN)
    return 0;

  return (int)reverse;
}

// #8. String to Integer (atoi)
int myAtoi(char *s) {
  int FlagNeg = 1;
  long result = 0;
  int i = 0;

  while (s[i] == ' ')
    i++;
  if (s[i] == '+' || s[i] == '-') {
    if (s[i] == '-')
      FlagNeg = -1;
    i++;
  }

  while (s[i] >= '0' && s[i] <= '9') {
    result = (result * 10) + (s[i] - '0');

    if (FlagNeg == 1 && result > INT_MAX)
      return INT_MAX;
    if (FlagNeg == -1 && -result < INT_MIN)
      return INT_MIN;
    i++;
  }

  return (int)(result * FlagNeg);
}

// #9. Palindrome Number
// also very easy no need to explain i can already understand just by looking at
// it for a few second
bool isPalindrome(int x) {
  if (x < 0)
    return false;
  long reverse = 0;
  int original = x;
  while (x != 0) {
    reverse = (reverse * 10) + (x % 10);
    x /= 10;
  }
  return original == reverse;
}

// #11. Container with most water

int maxArea(int *height, int heightSize) {
  int right = heightSize - 1;
  int left = 0;
  int maxVolume = 0;

  while (left < right) {
    int minHeight =
        (height[left] < height[right]) ? height[left] : height[right];
    int width = right - left;

    int currentVolume = width * minHeight;

    if (currentVolume > maxVolume)
      maxVolume = currentVolume;

    if (height[left] < height[right])
      left++;
    else
      right--;
  }
  return maxVolume;
}
