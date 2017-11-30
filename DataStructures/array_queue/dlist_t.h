#ifndef DLIST_T_H
#define DLIST_T_H

typedef struct node 
{
	int data;
	struct node *prev, *next;
}dlist_t;

dlist_t *dl_create_node(int data);

void dl_insert_first(dlist_t **head, int data); 

void dl_insert_last(dlist_t **head, int data);

void dl_print_list(dlist_t **head);

#endif
