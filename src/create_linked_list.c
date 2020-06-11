#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *create_linked_list(struct node *start) {
	struct node *new_node, *ptr;
	int num;

	printf("Enter -1 to terminate.\n");
	printf("Enter node's data: ");
	scanf("%d", &num);

	while (num != -1) {
		new_node = (struct node *) malloc(sizeof(struct node));
		new_node->data = num;

		if (start==NULL) {
			new_node->next = NULL;
			start = new_node;
		}
		else {
			ptr = start;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->next = NULL;
		}
		printf("Enter node's data: ");
		scanf("%d", &num);
	}
	return start;
}




