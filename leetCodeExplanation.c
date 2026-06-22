/*
 * leetcode #1
 */
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
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
// leetcode 2 (add two numbers)
struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  // create a dummy struct for easier data transfer
  struct ListNode dummy;
  // NULL it to avoid garbage value
  dummy.val = 0;
  dummy.next = NULL;

  int carry = 0;
  // current is pointing at the address of dummy therefore any value added to
  // current will goes to dummy
  struct ListNode *current = &dummy;
  // if any of this still exist then continue the loop
  while (l1 != NULL || l2 != NULL || carry != 0) {
    // set value for val1 and val2 if it exist and 0 if not
    int val1 = (l1 != NULL) ? l1->val : 0;
    int val2 = (l2 != NULL) ? l2->val : 0;

    int sum = val1 + val2 + carry;
    // extract 10 places so and carry it to the next addition
    carry = sum / 10;

    // allocate memory for the entire node
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    if (newNode == NULL)
      printf("failed to allocate memory");
    // extract 1 places
    newNode->val = sum % 10;
    newNode->next = NULL;

    // move current pointer to the tail of ListNode by changing it's memory
    // address
    current->next = newNode;
    current = current->next;

    // advance aslong as there is a value in it
    if (l1 != NULL)
      l1 = l1->next;
    if (l2 != NULL)
      l2 = l2->next;
  }
  // assign the pointer to the first valid node right after the dummy node
  struct ListNode *result = dummy.next;
  return result;
}

// # 7. Reverse Integer

// why is this so easy? yet is labeled medium for some reason. no explanation
// needed
int reverse(int x) {
  long rev = 0;
  while (x != 0) {
    rev = (rev * 10) + (x % 10);
    x /= 10;
  }
  if (rev >= INT_MAX || rev <= INT_MIN)
    return 0;
  return (int)rev;
}
