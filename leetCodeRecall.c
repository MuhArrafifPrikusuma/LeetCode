/**
 * # 1 two sum
 */
#include <stdlib.h>
typedef struct {
  int value;
  int index;
} HashMap;
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int hashSize = numsSize * 2;
  HashMap *hashTable = calloc(hashSize, sizeof(HashMap));

  int *occupied = calloc(hashSize, sizeof(int));

  int *result = malloc(2 * sizeof(int));
  *returnSize = 2;
  for (int i = 0; i < numsSize; i++) {
    int complement = target - nums[i];
    int hashIndex = abs(complement) % hashSize;

    while (occupied[hashIndex]) {
      if (hashTable[hashIndex].value == complement) {
        result[0] = hashTable[hashIndex].index;
        result[1] = i;

        free(occupied);
        free(hashTable);
        return result;
      }
      hashIndex = (hashIndex + 1) % hashSize;
    }
    int currentHashIndex = abs(nums[i]) % hashSize;
    while (occupied[currentHashIndex]) {
      currentHashIndex = (currentHashIndex + 1) % hashSize;
    }
    result[0] = hashTable[currentHashIndex].value = nums[i];
    result[1] = hashTable[currentHashIndex].index = i;
    occupied[currentHashIndex] = 1;
  }
  free(hashTable);
  free(occupied);
  *returnSize = 0;
  return NULL;
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
