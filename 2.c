#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void free_list(struct ListNode *head) {
  struct ListNode *tmp;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

struct ListNode *create_list_from_array(int values[], int size) {
  if (size == 0) {
    return NULL;
  }

  struct ListNode dummy;
  dummy.next = NULL;

  struct ListNode *current = &dummy;

  for (int i = 0; i < size; i++) {
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    if (new_node == NULL) {
      free_list(dummy.next);
      return NULL;
    }
    new_node->val = values[i];
    new_node->next = NULL;

    current->next = new_node;

    current = current->next;
  }

  return dummy.next;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  int rest = 0;
  struct ListNode temp;
  temp.next = NULL;

  struct ListNode *current = &temp;

  while (l1 != NULL || l2 != NULL || rest > 0) {
    int v1 = (l1 != NULL) ? l1->val : 0;
    int v2 = (l2 != NULL) ? l2->val : 0;
    int sum = v1 + v2 + rest;

    rest = sum / 10;
    sum %= 10;

    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = sum;
    newNode->next = NULL;
    current->next = newNode;
    current = current->next;

    printf("Sum: %i\t Rest: %i\n", sum, rest);

    if (l1 != NULL) {
      l1 = l1->next;
    }
    if (l2 != NULL) {
      l2 = l2->next;
    }
  }

  return temp.next;
}

int main() {

  int vals_1[] = {2, 4, 3};
  int vals_2[] = {5, 6, 4};

  struct ListNode *test_1 =
      create_list_from_array(vals_1, sizeof(vals_1) / sizeof(int));
  struct ListNode *test_2 =
      create_list_from_array(vals_2, sizeof(vals_2) / sizeof(int));

  addTwoNumbers(test_1, test_2);

  free_list(test_1);
  free_list(test_2);
}
