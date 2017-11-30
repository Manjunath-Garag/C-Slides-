#ifndef STACK_LL_H
#define STACK_LL_H

typedef struct node
{
int data;
struct node *next;
}slist_tt;

void ll_push(slist_tt **head, int data); //insert_first
void ll_pop(slist_tt **head);            //delete First.
void ll_peep(slist_tt **head);
void ll_peek(slist_tt **head);


#endif
