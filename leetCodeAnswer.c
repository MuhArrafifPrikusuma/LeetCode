/*
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
