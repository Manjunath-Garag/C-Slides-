#include<stdio.h>
#include<stdlib.h>
#include<queue_ll.h>

/*
typedef struct node
{
int data;
struct node *next;
}queue_list;
*/

int main()
{
	queue_list *head= NULL;
	int data,n;
	while(1)
	{
		printf("Enter your choice\n1:Push\n2:Pop\n3:Print_queue\n4:exit\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1: printf("Enter the data you want insert\n ");
				scanf("%d",&data);
				queue_insert_last(&head,data);
				break;

			case 2: queue_delete_first(&head);
				break;

			case 3: queue_print_list(&head);
				break;

			case 4: exit(1);

		}

	}
}
