/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node* current = head;
	while (current->next != NULL)
		current = current->next;
	struct node* newhead = current;
	current = head;
	while (current->next != NULL) {
		while (current->next->next != NULL)
			current = current->next;
		current->next->next = current;
		current->next = NULL;
		current = head;
	}
	return newhead;
}
