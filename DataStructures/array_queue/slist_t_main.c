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
		printf("Enter your Choice\n 1:Insert_First\n 2:Insert_Last\n 3:Delete_First\n 4:Delete_Last\n 5:Delete_List\n 6:Delete_ele\n 7:Mid value\n 8:Find_ele\n 9:Insert_Before\n 10:Insert_After\n 11:Insert_nth\n 12:nth pos from last\t Formula:Lenght-Postion.\n 13:Create_loop\n 14:Find_loop\n 15:INsert_Sorted\n 16:Print_list\n 17:Reverse_Iterative\n 18:Reverse_Recursive\n 19:Remove Dulpicates\n 20:sort\n 21:Exit\n");

		scanf("%d",&m);

		switch(m)
		{
			case 1: printf("Enter the data for Insert_first\n");
				scanf("%d",&data);
				insert_first(&head,data);
//we are passing the address of head i.e &head so that the changes are reflected directly on the address. BUT in the BIN-TREE we pass only head and we return the head back to the main. PASS BY REFRENCE.
//int bin-tree bs_tree *root =NULL; and while calling insert(root); and the root will be returned to main.PASS-BY-VALUE.
				break;

			case 2: printf("Enter the data for Insert_last\n");
				scanf("%d",&data);
				insert_last(&head,data);
				break;

			case 3: delete_first(&head);
				break;

			case 4: delete_last(&head);
				break;

			case 5: delete_list(&head);
				break;

			case 6: printf("Enetr the element You want to Delete\n");
				scanf("%d",&data);
				delete_ele(&head,data);
				break;

			case 7: mid(&head);
				break;

			case 8: find(&head);
				break;

			case 9: printf("Enter the Data\n");
			        scanf("%d",&data);
			        insert_before(&head,data);
			        break;

			case 10: printf("Enter the Data\n");
				 scanf("%d",&data);
				 insert_after(&head,data);
				 break;

			case 11: insert_nth(&head);
				 break;     

			case 12: nth_from_last(&head);
				 break;
     
			case 13: create_loop(&head);
				 break;     

			case 14: find_loop(&head);
				 break;
     
			case 15: printf("Enter the data \n");
				 scanf("%d",&data);
				 insert_sorted(&head,data);
				 break;

			case 16: print_list(&head);
				 break;

			case 17: reverse_itr(&head);
				 print_list(&head);
				 break;		
			case 18: reverse_recur(head);
				 break;		

			case 19: remove_duplicates(&head);
				 break;		
			case 20: sort(&head);
				 break;		
			case 21: exit(1);
				 break;
			
			default:printf("Enter proper Choice\n");
		}//switch
//		print_list(&head); we should'nt print outside the loop, cos we would make the list Circular
	}//while
}//main

