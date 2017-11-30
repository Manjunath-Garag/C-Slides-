#include<stdio.h>
#include<merge_sll.h>
#include<stdlib.h>

int main()
{
	int n,op,data;
	slist_tm *head1 = NULL;
	slist_tm *head2 = NULL;

	while(1)
	{
		printf("Enter your Option\n1:head1\t2:head2\n");
		scanf("%d",&op);

		printf("Enter your choice\n1:Insert_first\n2:INsert_last\n3:Print\n4:Merge_list\n5:Exit\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
				if(op == 1)
				{
					printf("Enter the data for head1\n");
					scanf("%d",&data);
					insert_first_for_msll(&head1,data);
				}
				else if(op == 2)
				{
					printf("Enter the data for head2\n");
					scanf("%d",&data);
					insert_first_for_msll(&head2,data);
				}
				break;


			case 2:
				if(op == 1)
				{
					printf("Enter the data for head1\n");
					scanf("%d",&data);
					insert_last_for_msll(&head1,data);
				}
				else if(op == 2)
				{
					printf("Enter the data for head2\n");
					scanf("%d",&data);
					insert_last_for_msll(&head2,data);
				}
				break;


			case 3:
				if(op==1)
					print_msll(&head1);
				else if(op == 2)
					print_msll(&head2);
				break;

			case 4:merge_list(&head1,&head2);
			       break;

			case 5:exit(1);

		}//switch

	}//while


}

