#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "../menu/menu.h"

struct node *create_linked_list(struct node *start) {
	struct node *new_node, *ptr;
	int num;

	printf("Creating a linked list. Enter node value, or -1 to terminate.\n");
	num = enter_node_value();

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
		num = enter_node_value();
	}
	return start;
}




