// # 1 two sum
#include <stdlib.h>
#include <string.h>

typedef struct {
  int val;
  int index;
} LookUp;
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int hashSize = numsSize * 2;

  LookUp *HashTable = calloc(hashSize, sizeof(LookUp));
  int *result = malloc(*returnSize * sizeof(int));
  int *occupied = calloc(hashSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int lookFor = target - nums[i];
    int tableIndex = abs(lookFor) % hashSize;
    while (occupied[tableIndex]) {
      if (HashTable[tableIndex].val == lookFor) {
        result[0] = HashTable[tableIndex].index;
        result[1] = i;

        free(HashTable);
        free(occupied);
        return result;
      }
      tableIndex = (tableIndex + 1) % hashSize;
    }
    int currentIndex = abs(nums[i]) % hashSize;
    while (occupied[currentIndex]) {
      currentIndex = (currentIndex + 1) % hashSize;
    }
    HashTable[currentIndex].val = nums[i];
    HashTable[currentIndex].index = i;
    occupied[currentIndex] = 1;
  }
  free(occupied);
  free(HashTable);
  *returnSize = 0;
  return NULL;
}

// # 2 add Two Numbers ( using linked list )
struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  int carry = 0;
  struct ListNode dummy;
  dummy.val = 0;
  dummy.next = 0;

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
  int maxLength = 0;
  int left = 0;
  for (int right = 0; s[right] != '\0'; right++) {
    uint currentChar = s[right];
    while (seen[currentChar] > left) {
      left = seen[currentChar];
    }
    seen[currentChar] = right + 1;
    int currentWindow = right - left + 1;
    if (currentWindow > maxLength) {
      maxLength = currentWindow;
    }
  }
  return maxLength;
}

// # 5 Longest Palindromic substring
int expand(char *s, int left, int right) {
  while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
    left--;
    right++;
  }
  return right - left - 1;
}
char *longestPalindrome(char *s) {
  int maxLength = 0;
  int len = strlen(s);
  int start = 0;

  for (int i = 0; i < len; i++) {
    int len1 = expand(s, i, i);
    int len2 = expand(s, i, i + 1);

    int currentLength = (len1 > len2) ? len1 : len2;

    if (currentLength > maxLength) {
      maxLength = currentLength;
      start = i - (maxLength - 1) / 2;
    }
  }
  s[start + maxLength] = '\0';

  return &s[start];
}
