/*index
 * leetcode #1
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int key;
  int index;
} HashEntry;

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int *result = malloc(*returnSize * sizeof(int));

  int tableSize = numsSize * 2;
  HashEntry *hashTable = calloc(tableSize, sizeof(HashEntry));
  int *occupied = calloc(tableSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int missingPartner = target - nums[i];
    int hashIndex = abs(missingPartner) % tableSize;
    while (occupied[hashIndex]) {
      if (hashTable[hashIndex].key == missingPartner) {
        result[0] = hashTable[hashIndex].index;
        result[1] = i;
        free(hashTable);
        free(occupied);
        return result;
      }
      hashIndex = (hashIndex + 1) % tableSize;
    }
    int insertIndex = abs(nums[i]) % tableSize;
    while (occupied[insertIndex]) {
      insertIndex = (insertIndex + 1) % tableSize;
    }
    hashTable[insertIndex].key = nums[i];
    hashTable[insertIndex].index = i;
    occupied[insertIndex] = 1;
  }
  free(hashTable);
  free(occupied);
  return NULL;
}
/*
 * leetcode #9
 */
bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  long reverse = 0;
  int remainder;
  int original = x;
  while (x != 0) {
    remainder = x % 10;
    reverse = reverse * 10 + remainder;
    x /= 10;
  }
  return original == reverse;
}
/*
 * leetCode #13
 */
int romanToValue(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return 0;
  }
}
int romanToInt(char *s) {
  int total = 0;
  int length = strlen(s);
  for (int i = 0; i < length; i++) {
    int currentValue = romanToValue(s[i]);
    if (i + 1 < length && currentValue < romanToValue(s[i + 1])) {
      total -= currentValue;
    } else {
      total += currentValue;
    }
  }
  return total;
}
/*
 * leetCode #14
 */
char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize == 0)
    return "";

  char *base = strs[0];

  for (int i = 0; base[i] != '\0'; i++) {
    char currentChar = base[i];

    for (int j = 0; j < strsSize; j++) {
      if (strs[j][i] == '\0' || strs[j][i] != currentChar) {
        base[i] = '\0';
        return base;
      }
    }
  }
  return base;
}
/*
 * leetCode #15
 */
// FIXME: able to return in 2D array but only able to take the very first array
int compareAscend(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}
int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), compareAscend);

  int capacity = 16;
  int **result = malloc(capacity * sizeof(int));
  *returnSize = 0;

  for (int i = 0; i < numsSize - 2; i++) {
    if (nums[i] > 0)
      break;
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int left = i + 1;
    int right = numsSize - 1;
    if (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum == 0) {
        if (*returnSize >= capacity) {
          capacity *= 2;
          result = realloc(result, capacity * sizeof(int *));
        }
        result[*returnSize] = malloc(3 * sizeof(int));
        result[*returnSize][0] = nums[i];
        result[*returnSize][1] = nums[left];
        result[*returnSize][2] = nums[right];
        // () to prevent unused expression
        (*returnSize)++;
        while (left < right && nums[left] == nums[left + 1])
          left++;
        while (left < right && nums[right] == nums[right - 1])
          right--;
        left++;
        right--;
      } else if (sum < 0) {
        left++;
      } else {
        right++;
      }
    }
  }
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  for (int i = 0; i < *returnSize; i++) {
    (*returnColumnSizes)[i] = 3;
  }
  return result;
}

// # 2 add Two Numbers

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

// #3 Longest Substring Without repeating characters

int lengthOfLongestSubstring(char *s) {
  int lastSeen[128] = {0};
  int maxLength = 0;
  int left = 0;

  for (int right = 0; s[right] != '\0'; right++) {
    unsigned char currentChar = s[right];

    if (lastSeen[currentChar] > left) {
      left = lastSeen[currentChar];
    }
    lastSeen[currentChar] = right + 1;

    int currentWindowLength = right - left + 1;
    if (currentWindowLength > maxLength) {
      maxLength = currentWindowLength;
    }
  }
  return maxLength;
}
