#include<stdio.h>
#include<stdlib.h>
//insert last. 		1st:10		2nd:20 		3rd:30		4th:40
//delete first.

typedef struct node
{
	int data;
	struct node *next;
}queue_list;

queue_list *create_node(int data)
{
	queue_list *new = malloc(sizeof(queue_list));
	new->data = data;
	new->next = NULL;
	return new;
}

void queue_delete_first(queue_list **head)	//delete first In Queue because it's Nature is FIFO.
{
	queue_list *ptr = *head;
	queue_list *prev = *head;
	if (*head == NULL)
	{
		printf("Queue is Empty\n");
	}
	else if(ptr->next == NULL)	//if only 1 ele is Present.
	{
		free(ptr);
		*head = NULL;
	}
	else
	{
	(*head)=(*head)->next;
	free(ptr);
	}
}

void queue_print_list(queue_list **head)
{
	queue_list *ptr=*head;
	if(*head == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		while(ptr != NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}

	}
}


void queue_insert_last(queue_list **head,int data)	//inserting the elements IN The Order FIFO. for Queue.
{
	queue_list *ptr=*head;

	if(*head == NULL)
	{
		*head = create_node(data);
	}
	else
	{	
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		queue_list *new=create_node(data);
		ptr->next = new;
		//new->next = NULL;
	}
}
