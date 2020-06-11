#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


void swap_nodes(struct node *a, struct node *b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

struct node *sort_list(struct node *start) {
	struct node *ptr, *ptrnext;
	short not_sorted = 1;

	if (start == NULL) {
		printf("The list is empty, there is nothing to delete.\n");
		return NULL;
	}

	if (start->next == NULL) {
		printf("The list contains only one element, hence is sorted.\n");
		return start;
	}

	while (not_sorted) {
		ptr = start;
		ptrnext = ptr->next;
		not_sorted = 0;

		while(ptrnext != NULL) {
			if (ptr->data > ptrnext->data) {
				swap_nodes(ptr, ptrnext);
				not_sorted++;
			}
			ptr = ptrnext;
			ptrnext = ptrnext->next;
		}
	}

	return start;
}





