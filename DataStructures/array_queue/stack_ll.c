#include<stdio.h>
#include<stdlib.h>
//IMplmenting Stack Functions Using Linked List.
//Insert-First for PUSH			5th:50   	4th:40 		3rd:30		 2nd:20		 1st:10
//Delete First for POP	

typedef struct node
{
	int data;
	struct node *next;
}slist_tt;

slist_tt *ll_create_node(int data)	//FUnction PONITER.
{
	slist_tt *new =malloc(sizeof(slist_tt));
	new->data=data;
	new->next = NULL;
	return new;     //it will return the addresses of the Entire Structure.
}

void ll_push(slist_tt **head, int data)	//insert_first
{
	slist_tt *ptr=*head;
	if (*head == NULL)
	{
		*head = ll_create_node(data);
	}
	else
	{
		slist_tt *new = ll_create_node(data);
		new->next=(*head);
		*head = new;
	}
}



void ll_pop(slist_tt **head)		//delete First.
{
	slist_tt *ptr=*head;
	if(*head == NULL)
		printf("Stack is Empty\n");

	else if( (ptr)->next == NULL)  //if there is only 1 element.
	{
		printf("%d",(ptr)->data);
		free(ptr);
		*head = NULL;
	}
	else
	{
		printf("%d",(*head)->data);
		(*head)=ptr->next;
		free(ptr);
	}
}


void ll_peep(slist_tt **head)
{
	slist_tt *ptr =*head;
	while(ptr != NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void ll_peek(slist_tt **head)
{
	if(*head == NULL)
		printf("The Stack is Empty\n");
	else
		printf("The Topmost element in the Stack is %d\n",(*head)->data);
	//return ((*head)->data);	//printf("The Topmost element in the Stack is %d\n",(*head)->data);
}
