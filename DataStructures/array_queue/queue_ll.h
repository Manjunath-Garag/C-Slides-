#ifndef QUEUE_LL_H
#define QUEUE_LL_H

typedef struct node
{
int data;
struct node *next;
}queue_list;

void queue_insert_last(queue_list **head,int data);
void queue_delete_first(queue_list **head);
queue_list *create_node(int data);

#endif
