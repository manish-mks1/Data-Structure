#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};

// Insert at the beginning
void insertAtFront(struct node **head_ref, int new_val) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->val = new_val;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
void insertAtLast(struct node* prev_node, int new_val) {
  if (prev_node == NULL) {
  printf("the given previous node cannot be NULL");
  return;
  }

  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->val = new_val;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}
void insertAtEnd(struct node **head_ref, int new_val) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  struct node* last = *head_ref; 
  new_node->val = new_val;
  new_node->next = NULL;
  if (*head_ref == NULL) {
  *head_ref = new_node;
  }
  else{
  	while (last->next != NULL) 
  		last = last->next;
  	last->next = new_node;
	}
}

// Delete a node
void deletenode(struct node** head_ref, int key) {
  struct node *temp = *head_ref, *prev;

  if (temp != NULL && temp->val == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->val != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Search a node
int searchnode(struct node** head_ref, int key) {
  struct node* current = *head_ref;

  while (current != NULL) {
  if (current->val == key) return 1;
  current = current->next;
  }
  return 0;
}

// Sort the linked list
void sortLinkedList(struct node** head_ref) {
  struct node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;

    while (index != NULL) {
    if (current->val > index->val) {
      temp = current->val;
      current->val = index->val;
      index->val = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}

// Print the linked list
void printList(struct node* node) {
  while (node != NULL) {
  printf(" %d ", node->val);
  node = node->next;
  }
}

// Driver program
int main() {
  struct node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deletenode(&head, 3);
  printList(head);

  int item_to_find = 3;
  if (searchnode(&head, item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d is not found", item_to_find);
  }

  sortLinkedList(&head);
  printf("\nSorted List: ");
  printList(head);
}
