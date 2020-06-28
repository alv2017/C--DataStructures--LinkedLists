#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *insert_first(struct node *start, int val, short *op_status) {
	struct node *new_node;
	new_node = NULL;

	// operation status
	*op_status = 0;

	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Unable to insert a new node: Memory allocation failure.\n");
		return start;
	}

	new_node->data = val;
	new_node->next = start;
	start = new_node;
	// End operation
	*op_status = 1;
	return start;
}

struct node *insert_last(struct node *start, int val, short *op_status) {
	struct node *new_node, *ptr;
	new_node = NULL;
	ptr = start;

	// operation status
	*op_status = 0;

	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Unable to insert a new node: Memory allocation failure.\n");
		return start;
	}

	new_node->data = val;
	new_node->next = NULL;

	if (start == NULL) {
		start = new_node;
		*op_status = 1;
		return start;
	}

	while(ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = new_node;
	*op_status = 1;
	return start;
}

struct node *insert_before_node(struct node *start, int before_val, int val, short *op_status) {
	struct node *ptr, *preptr;
	*op_status = 0;
	preptr = NULL;
	ptr = start;

	if (start == NULL) {
		printf("Unable to insert a new node. There is no node satisfying the insertion criteria.\n");
		return start;
	}

	while (ptr != NULL) {
		if (ptr->data == before_val) {
			struct node *new_node;
			new_node = (struct node *)malloc(sizeof(struct node));
			if (new_node == NULL) {
				printf("Unable to insert a new node: Memory allocation failure.\n");
				return start;
			}
			new_node->data = val;
			new_node->next = ptr;
			if (preptr != NULL){
				preptr->next = new_node;
			}
			else {
				start = new_node;
			}
			*op_status = 1;
			return start;
		}
		preptr = ptr;
		ptr = ptr->next;
	}

	printf("Unable to insert a new node. There is no node satisfying the insertion criteria.\n");
	return start;
}

struct node *insert_after_node(struct node *start, int after_val, int val, short *op_status) {
	struct node *ptr;
	*op_status = 0;
	ptr = start;

	if (start == NULL) {
		printf("Unable to insert a new node. There is no node satisfying the insertion criteria.\n");
		return start;
	}

	while(ptr != NULL) {
		if (ptr->data == after_val) {
			struct node *new_node;
			new_node = (struct node *)malloc(sizeof(struct node));
			if (new_node == NULL) {
				printf("Unable to insert a new node: Memory allocation failure.\n");
				return start;
			}
			new_node->data = val;
			new_node->next = ptr->next;
			ptr->next = new_node;
			*op_status = 1;
			return start;
		}
		ptr = ptr->next;
	}

	printf("Unable to insert a new node. There is no node satisfying the insertion criteria.\n");
	return start;
}
