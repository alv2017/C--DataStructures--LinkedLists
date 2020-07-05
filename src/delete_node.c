#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *delete_first(struct node *start, short *op_status) {
	struct node *ptr;
	*op_status = 0;
	ptr = start;

	if (ptr == NULL) {
		printf("The list is empty, there is nothing to delete.\n");
		return NULL;
	}

	start = start->next;
	free(ptr);
	*op_status = 1;
	return start;
}

struct node *delete_last(struct node *start, short *op_status) {
	struct node *ptr, *preptr;
	*op_status = 0;
	preptr = NULL;
	ptr = start;

	if (start == NULL) {
		printf("The list is empty, there is nothing to delete.\n");
		return NULL;
	}

	if (ptr->next == NULL) {
		free(ptr);
		*op_status = 1;
		return NULL;
	}

	while (ptr->next != NULL) {
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = NULL;
	free(ptr);
	*op_status = 1;
	return start;
}

struct node *delete_node(struct node *start, int node_val, short *op_status) {
	struct node *ptr, *preptr;
	*op_status = 0;
	ptr = start;
	preptr = NULL;

	if (ptr == NULL) {
		printf("Unable to delete a node. There is no node matching your criteria.\n");
		return NULL;
	}

	while (ptr != NULL) {
		if (ptr->data == node_val) {
			if (preptr == NULL) {
				start = ptr->next;
			}
			else {
				preptr->next = ptr->next;
			}
			free(ptr);
			*op_status = 1;
			return start;
		}
		preptr = ptr;
		ptr = ptr->next;
	}

	printf("Unable to delete a node. There is no node matching your criteria.\n");
	return start;
}

struct node *delete_node_before(struct node *start, int before_val, short *op_status) {
	struct node *ptr, *preptr, *ptrnext;
	*op_status = 0;

	if (start == NULL || start->next == NULL) {
		printf("Unable to delete a node. There is no node matching your criteria.\n");
		return NULL;
	}

	preptr = NULL;
	ptr = start;
	ptrnext = start->next;

	while(ptrnext != NULL) {
		if (ptrnext->data == before_val) {
			if (preptr == NULL) {
				start = ptrnext;
			}
			else {
				preptr->next = ptrnext;
			}
			free(ptr);
			*op_status = 1;
			return start;
		}
		preptr = ptr;
		ptr = ptrnext;
		ptrnext = ptrnext->next;
	}

	printf("Unable to delete a node. There is no node matching your criteria.\n");
	return start;
}

struct node *delete_node_after(struct node *start, int after_val, short *op_status){
	struct node *ptr, *preptr;
	*op_status = 0;

	if (start == NULL || start->next == NULL) {
		printf("Unable to delete a node. There is no node matching your criteria.\n");
		return NULL;
	}
	preptr = start;
	ptr = start->next;

	while(ptr != NULL) {
		if (preptr->data == after_val) {
			preptr->next = ptr->next;
			free(ptr);
			*op_status = 1;
			return start;
		}
		preptr = ptr;
		ptr = ptr->next;
	}
	printf("Unable to delete a node. There is no node matching your criteria.\n");
	return start;
}

struct node *delete_node_n(struct node *start, long n, short *op_status) {
	*op_status = 0;
	long node_counter = 1;
	struct node *ptr, *preptr;
	preptr = NULL;
	ptr = start;

	// The list is empty
	if (start == NULL) {
		printf("The list is empty. Nothing to delete.\n");
		return start;
	}
	// Navigate to the n-th node
	while(ptr->next != NULL) {
		if (node_counter == n) break;
		preptr = ptr;
		ptr = ptr->next;
		node_counter++;
	}
	// We have less than n nodes in the list
	if (node_counter < n) {
		printf("There are less than %ld nodes in the list. ", n);
		printf("Nothing to delete.\n");
		return start;
	}
	// All other cases
	if (preptr == NULL) {
		start = ptr->next;
	}
	else {
		preptr->next = ptr->next;
	}
	free(ptr);
	*op_status = 1;
	return start;
}



