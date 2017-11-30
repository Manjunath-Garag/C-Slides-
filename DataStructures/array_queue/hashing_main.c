#include<stdio.h>
#include<stdlib.h>
#include<hashing.h>

int hash(char *key)
{
	char ch = *key;
	if(isupper(ch))
		ch=tolower(ch);
	return (ch - 97);
}


int main()
{
	node_t *head = NULL;
	int age,op,res,i;
	double phone_no;
	char name[20];
	node_t *arr[26]= {0};	//arr is an array of 26 STRUCTURE Pointers.
	while(1)
	{
		printf("Enter your choice\n1:Insert_data\n2:Search\n3:Delete\n4:Print_List\n5:Print_Table\n6:Delete_Table\n7:exit\n");
		scanf("%d",&op);

		switch(op)
		{
			case 1: 
				printf("Enter the Name, Age,Phone_no\n");
				scanf("%s%d%lf",name,&age,&phone_no);
				res=hash(name);
				printf("res:%d\n",res);
				if(arr[hash(name)] == NULL) //a[0] == NULL <= a[hash(apple)] ==NULL a[0] and *head botha are same.
				{
					arr[hash(name)] = create_nodes(name,age,phone_no);
				}
				else
					insert_nodes(&arr[hash(name)],name,age,phone_no); //like sending (&head)
				break;

			case 2: printf("Enter the Name you want to Search\n");
				scanf("%s",name);
				res=hash(name);
				if(arr[hash(name)] == NULL)
					printf("The list is Empty\n");
				else
					search_nodes(&arr[hash(name)],name);			
				break;

			case 3: printf("Enter the Name you want to Delete\n");
				scanf("%s",name);
				res=hash(name);
				if(arr[hash(name)] == NULL)
					printf("The list is Empty\n");
				else
					delete_nodes(&arr[hash(name)],name);			
				break;
			case 4:printf("Enter the alphabet you want to enter");
			       scanf("%s",name);
			       res=hash(name);printf("res from print %d\n",res);
			       if(arr[hash(name)] == NULL)
				       printf("The list is Empty\n");
			       else
				       print_nodes(&arr[hash(name)]);
			       break;
			case 5: for(i=0;i<26;i++)
					print_details(arr[i]);
				break;
			case 6: for(i=0;i<26;i++)
					delete_table(&arr[i]); //should use Double Pointers otherwise Only name 1st Att gets deleted.
				break;
			case 7:exit(1);

		}

	}//switch
}//while

