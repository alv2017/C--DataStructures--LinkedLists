#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Node of linked list
struct node
{
	int data;
	struct node *next;
};

// Display linked list to stdin
void display_list(struct node *start);

// Insert start node
struct node *insert_first(struct node *start, int val, short *op_status);
// Insert end node
struct node *insert_last(struct node *start, int val, short *op_status);
// Insert node before the node with a given value
struct node *insert_before_node(struct node *start, int before_val, int val, short *op_status);
// Insert node after the node with a given value
struct node *insert_after_node(struct node *start, int after_val, int val, short *op_status);

// Delete the first node of the linked list
struct node *delete_first(struct node *start, short *op_status);
// Delete the last node of the linked list
struct node *delete_last(struct node *start, short *op_status);
// Delete node by value
struct node *delete_node(struct node *start, int node_val, short *op_status);
// Delete node before the node with a given value
struct node *delete_node_before(struct node *start, int before_val, short *op_status);
// Delete node after the node with a given value
struct node *delete_node_after(struct node *start, int after_val, short *op_status);
// Delete n-th node
struct node *delete_node_n(struct node *start, long n, short *op_status);

// Delete entire list
struct node *delete_list(struct node *start, short *op_status);

// Sort linked list
struct node *sort_list(struct node *start);

#endif





