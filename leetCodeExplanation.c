/*
 * leetcode #1
 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int key;
  int index;
} HashEntry;

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  // since it asked it to be 2
  *returnSize = 2;
  int *result = malloc(*returnSize * sizeof(int));

  // table big, collision clear, runtime fast
  int tableSize = numsSize * 2;
  // calloc is like malloc but replaces with 0 instead of garbage value
  HashEntry *hashTable = calloc(tableSize, sizeof(HashEntry));
  // see array, if is not empty is 1 if yes empty 0
  int *occupied = calloc(tableSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int missingPartner = target - nums[i];
    // determine where store data
    int hashIndex = abs(missingPartner) % tableSize;
    // slot occupied do search
    while (occupied[hashIndex]) {
      // if correct, missing found
      if (hashTable[hashIndex].key == missingPartner) {
        result[0] = hashTable[hashIndex].index;
        result[1] = i;
        // good memory no leak
        free(hashTable);
        free(occupied);
        return result;
      }
      // occupied not same do next index
      hashIndex = (hashIndex + 1) % tableSize;
    }
    // determine index
    int insertIndex = abs(nums[i]) % tableSize;
    while (occupied[insertIndex]) {
      // not empty, next index
      insertIndex = (insertIndex + 1) % tableSize;
    }
    // empty, then assign
    hashTable[insertIndex].key = nums[i];
    hashTable[insertIndex].index = i;
    // to show not empty
    occupied[insertIndex] = 1;
  }
  free(hashTable);
  free(occupied);
  // want return pointer, NULL > 0, but not if non pointer
  return NULL;
}

/*
 * leetcode #9
 */
bool isPalindrome(int x) {
  // negative can't palindrome
  if (x < 0) {
    return false;
  }
  long reverse = 0;
  int remainder;
  int original = x;
  // reverse reverse first and last int
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
int compareAscend(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}
int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), compareAscend);

  int capacity = 16;
  int **result = malloc(capacity * sizeof(int));
  *returnSize = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0)
      break;
  }
}
