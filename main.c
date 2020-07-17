#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "src/linked_list.h"

#define clear() printf("\033[H\033[J")

const char *menu[] = {
		" 1. Create a linked list",
		" 2. Display list",
		" 3. Add node at the beginning",
		" 4. Add node at the end",
		" 5. Add node before a given node",
		" 6. Add node after a given node",
		" 7. Delete node from the beginning",
		" 8. Delete node from the end",
		" 9. Delete node by value",
		"10. Delete node before given node",
		"11. Delete node after given node",
		"12. Delete the n-th node",
		"13. Sort the list",
		"14. Delete entire list",
		"15. Exit",
		NULL
};

int main(int argc, char **argv) {
	// Menu
	short opt;
	const short MINOPT = 1;
	const short MAXOPT = get_menu_length(menu);

	// Linked List
	short op_status = 0;
	struct node *llist;
	int node_value, before_value, after_value;
	llist = NULL;

	clear();
	display_menu(menu);
	opt = select_option(MINOPT, MAXOPT);
	printf("You have selected: %d\n", opt);

	while (1) {
		switch (opt) {
			case 15:
				// Exiting the program
				clear();
				if (llist != NULL) {
					llist = delete_list(llist, &op_status);
				}
				printf("Exiting the program.\n");
				return 0;

			case 1:
				// Creating a new linked list
				clear();
				if (llist != NULL) {
					printf("The list already exists. ");
					printf("You need to delete the existing list before creating a new one.\n");
				} else {
					printf("Enter the value of the new node or press ENTER to exit.\n");
					node_value = enter_node_value(&op_status);
					while(op_status == 1) {
						llist = insert_last(llist, node_value, &op_status);
						printf("Enter the value of the new node or press ENTER to exit.\n");
						node_value = enter_node_value(&op_status);
					}
				}
				break;

			case 2:
				// Displaying linked list
				clear();
				printf("Displaying a list:\n");
				display_list(llist);
				break;

			case 3:
				// Adding new node at the beginning
				clear();
				printf("Adding a new node at the beginning.\n");
				node_value = enter_node_value(&op_status);
				llist = insert_first(llist, node_value, &op_status);

				if (op_status == 0) {
					printf("Failed to add a new node\n");
				}
				else {
					printf("New node has been added.\n");
					op_status = 0;
				}
				break;

			case 4:
				// Adding a new node at the end
				clear();
				printf("Adding a new node at the end.\n");
				node_value = enter_node_value(&op_status);
				llist = insert_last(llist, node_value, &op_status);

				if (op_status == 0) {
					printf("Failed to add a new node\n");
				}
				else {
					printf("New node has been added.\n");
					op_status = 0;
				}
				break;

			case 5:
				// Adding a new node before a given node
				clear();
				printf("Adding a new node before a given node.\n");
				printf("Enter the value of the node before which you want to insert a new node.\n");
				before_value = enter_node_value(&op_status);
				printf("Enter the value of the new node.\n");
				node_value = enter_node_value(&op_status);
				llist = insert_before_node(llist, before_value, node_value, &op_status);

				if (op_status == 0) {
					printf("Failed to add a new node\n");
				}
				else {
					printf("New node has been added.\n");
					op_status = 0;
				}
				break;

			case 6:
				// Adding a new node after a given node
				clear();
				printf("Adding a new node after a given node.\n");
				printf("Enter the value of the node after which you want to insert a new node.\n");
				after_value = enter_node_value(&op_status);
				printf("Enter the value of the new node.\n");
				node_value = enter_node_value(&op_status);
				llist = insert_after_node(llist, after_value, node_value, &op_status);

				if (op_status == 0) {
					printf("Failed to add a new node\n");
				}
				else {
					printf("New node has been added.\n");
					op_status = 0;
				}
				break;

			case 7:
				// Deleting a node at the beginning
				clear();
				printf("Deleting a node at the beginning.\n");
				op_status = 0;
				llist = delete_first(llist, &op_status);

				if (op_status == 0) {
					printf("Failed to delete a node.\n");
				}
				else {
					printf("Node has been deleted.\n");
					op_status = 0;
				}
				break;

			case 8:
				// Deleting a node at the end
				clear();
				printf("Deleting a node at the end.\n");
				llist = delete_last(llist, &op_status);

				if (op_status == 0) {
					printf("Failed to delete a node.\n");
				}
				else {
					printf("Node has been deleted.\n");
					op_status = 0;
				}
				break;

			case 9:
				// Deleting a node with a given value
				clear();
				printf("Deleting a node with a given value.\n");
				node_value = enter_node_value(&op_status);
				llist = delete_node(llist, node_value, &op_status);

				if (op_status == 0) {
					printf("Failed to delete a node.\n");
				}
				else {
					printf("Node has been deleted.\n");
					op_status = 0;
				}
				break;

			case 10:
				// Deleting a node before the node with a given value
				clear();
				printf("Deleting a node before the node with a given value.\n");
				printf("Enter the value of the node that goes before the node you want to delete.\n");
				before_value = enter_node_value(&op_status);
				llist = delete_node_before(llist, before_value, &op_status);

				if (op_status == 0) {
					printf("Failed to delete a node.\n");
				}
				else {
					printf("Node has been deleted.\n");
					op_status = 0;
				}
				break;

			case 11:
				// Deleting a node after the given node
				clear();
				printf("Deleting a node after the given node.\n");
				printf("Enter the value of the node after which you want to delete a node.\n");
				after_value = enter_node_value(&op_status);
				llist = delete_node_after(llist, after_value, &op_status);

				if (op_status == 0) {
					printf("Failed to delete a node.\n");
				}
				else {
					printf("Node has been deleted.\n");
					op_status = 0;
				}
				break;

			case 12:
				// Deleting the n-th node
				clear();
				printf("Deleting the n-th node.\n");
				long node_number;
				node_number = enter_node_number(&op_status);
				printf("\nTrying to delete node number %ld.\n", node_number);
				llist = delete_node_n(llist, node_number, &op_status);
				if (op_status==1) {
					printf("Node has been deleted.\n");
				}
				else {
					printf("Failed to delete the node.\n");
				}
				break;

			case 13:
				// Sorting a list
				clear();
				printf("Sort a list.\n");
				llist = sort_list(llist);
				break;

			case 14:
				clear();
				printf("Deleting entire list.\n");
				llist = delete_list(llist, &op_status);

				if (op_status == 0) {
					printf("Failed to delete the list.\n");
				}
				else {
					printf("Linked list has been deleted.\n");
					op_status = 0;
				}
				break;

			default:
			  printf("Unknown option: %d\n", opt);
			  break;
		}
		// Asking user for further actions
		display_menu(menu);
		opt = select_option(MINOPT, MAXOPT);
		printf("You have selected: %d\n", opt);
	}
	return 0;
}
