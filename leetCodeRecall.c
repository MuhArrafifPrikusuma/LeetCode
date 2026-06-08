// # 1 two sum
#include <stdlib.h>
#include <string.h>
typedef struct {
  int value;
  int indexVal;
} HashMap;
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int hashSize = numsSize * 2;
  *returnSize = 2;

  int *result = malloc(*returnSize * sizeof(int));

  HashMap *hashTable = calloc(hashSize, sizeof(HashMap));
  int *occupied = calloc(hashSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int missing = target - nums[i];
    int hashIndex = abs(missing) % hashSize;

    while (occupied[hashIndex]) {
      if (hashTable[hashIndex].value == missing) {
        result[0] = hashTable[hashIndex].indexVal;
        result[1] = i;

        free(hashTable);
        free(occupied);
        return result;
      }
      hashIndex = (hashIndex + 1) % hashSize;
    }
    int insertIndex = abs(nums[i]) % hashSize;
    while (occupied[insertIndex]) {
      insertIndex = (insertIndex + 1) % hashSize;
    }
    result[0] = hashTable[insertIndex].value = nums[i];
    result[0] = hashTable[insertIndex].indexVal = i;
    occupied[insertIndex] = 1;
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
