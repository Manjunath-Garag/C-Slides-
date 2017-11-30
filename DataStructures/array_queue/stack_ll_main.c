#include<stdio.h>
#include<stdlib.h>
#include<stack_ll.h>

int main()
{
	int max,n,data;
	printf("Enter the size of the array\n");
	scanf("%d",&max);
	slist_tt *head = NULL;


	while(1)
	{
		printf("Enter your choice\n1:Push\n2:Pop\n3:Peep\n4:Peek\n5:Exit\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1: printf("Enter the Data you want to PUSH\n");
				scanf("%d",&data);
				ll_push(&head,data);
				break;

			case 2:ll_pop(&head);
			       //printf("The deleted value was LIFO: %d\n",ret);
			       break;

			case 3:ll_peep(&head);
			       break;

			case 4:ll_peek(&head);
			       break;

			case 5:exit(1);
		}

	}
}
