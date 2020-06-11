#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *delete_list(struct node *start, short *op_status) {
	struct node *ptr, *preptr;
	*op_status = 0;

	ptr = start;
	preptr = NULL;

	if (ptr == NULL) {
		printf("The list is empty, there is nothing to delete.\n");
		return start;
	}

	while(ptr != NULL) {
		preptr = ptr;
		ptr = ptr->next;
		free(preptr);
	}
	printf("The list has been deleted.\n");
	start = ptr;
	*op_status = 1;
	return start;
}
