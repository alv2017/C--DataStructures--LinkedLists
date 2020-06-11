#include <stdio.h>
#include "linked_list.h"


void display_list(struct node *start) {
	struct node *ptr;
	ptr = start;
	size_t counter = 0;

	if (ptr == NULL) {
		printf("The list is empty.\n");
		return;
	}

	while (ptr != NULL ) {
		counter ++;
		printf("Node id: %lu; address: %p; value: %d\n", counter, ptr, ptr->data);
		ptr = ptr->next;
	}
}

