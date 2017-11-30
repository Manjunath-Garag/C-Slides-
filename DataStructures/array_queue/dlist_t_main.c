#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<slist_t.h>


int main()
{
	int m,data;
	slist_t *head = NULL;
	while(1)
	{
		printf("Enter your Choice\n 1:Insert_First\n 2:Insert_Last\n 3:Delete_First\n 4:Delete_Last\n 5:Delete_List\n 6:Delete_ele\n 7:Insert_Before\n 8:Insert_After\n 9:Exit\n");

		scanf("%d",&m);

		switch(m)
		{
			case 1: printf("Enter the data for Insert_first\n");
				scanf("%d",&data);
				dl_insert_first(&head,data);
				break;

			case 2: printf("Enter the data for Insert_last\n");
				scanf("%d",&data);
				dl_insert_last(&head,data);
				break;

			case 3: dl_delete_first(&head);
				break;

			case 4: dl_delete_last(&head);
				break;

			case 5: dl_delete_list(&head);
				break;

			case 6: printf("Enetr the element You want to Delete\n");
				scanf("%d",&data);
				dl_delete_ele(&head,data);
				break;



			case 7: printf("Enter the Data\n");
			        scanf("%d",&data);
			        dl_insert_before(&head,data);
			        break;

			case 8: printf("Enter the Data\n");
				 scanf("%d",&data);
				 dl_insert_after(&head,data);
				 break;


			case 9: exit(0);
				 break;

		}//switch
		dl_print_list(&head);
		if(m == 9)
			break;
	}//while
}//main

