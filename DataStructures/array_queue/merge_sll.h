#ifndef MERGE_SLL_H
#define MERGE_SLL_H

typedef struct node
{
	int data;
	struct node *next;
}slist_tm;

slist_tm *create_node_for_merge_sll(int data);
void insert_first_for_msll(slist_tm **head, int data);
void insert_last_for_msll(slist_tm **head, int data);
void print_msll(slist_tm **head);
void bubble_sort_msll(slist_tm ** head);

#endif
