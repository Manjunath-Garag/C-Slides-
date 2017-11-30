#ifndef SLIST_T_H
#define SLIST_T_H

typedef struct node 
{
	int data;
	struct node *next;
}slist_t;

void insert_first(slist_t **head, int data); 
void insert_last(slist_t **head, int data);
void print_list(slist_t **head);
slist_t *create_node(int data);

void mid(slist_t **head);
void delete_first(slist_t **head);
void delete_last(slist_t **head);
void delete_list(slist_t **head);
void find(slist_t **head);
void delete_ele(slist_t **head,int data);

void insert_before(slist_t **head,int data);
void nth_from_last(slist_t **head);
void create_loop(slist_t **head);
void find_loop(slist_t **head);
void insert_sorted(slist_t **head,int data);
void reverse_itr(slist_t **head);
void remove_duplicates(slist_t **head);
void sort(slist_t ** head);


#endif
