#include<stdio.h>
#include<stdlib.h>
//   The prototype has to be written in the ".h" file. 

typedef struct node 
{
	int data;
	struct node *next;
}slist_t;

slist_t *create_node(int data)		//Function , which returns the address of the Structure.
{
	slist_t *new=malloc(sizeof(slist_t));	// malloc is Dynamic Mem Alloacation, the memeory space has to be Pointed by A POINTER.
	new->data = data;
	new->next = NULL;
	return new;
}

void insert_first(slist_t **head, int data)  //A head would be Pointing to Structure
{       // **head because we need to extract the values of struct i.e data and link.

	if(*head == NULL) //head is not pointing to any Structure, it is Dynamically allocated with a Struct.
	{
		//*head here means we are actually checking the value. head is PTR to structure,
		/*  slist_t *new = malloc(sizeof(slist_t)); //here im creating a structure of type struct, with name new,
		    new->data = data;       // value will be written.
		    new->next = NULL;       //Link would be made as Null. 

		 *head= new;     //now head is pointing to new. head value would be Reflected in the main, cos pass by ref. */

		*head=create_node(data);	// this line is replacemnet for the above 4 lines
	}
	else
	{
		/*  slist_t *new = malloc(sizeof(slist_t)); //here im creating a structure of type struct, with name new,
		    new->data = data;       // value will be written.
		    new->next = *head;      //Link would be made as Null.

		 *head= new;  */

		slist_t *new =create_node(data);
		new->next = *head;
		*head = new;
	}
}//insert_first.

void insert_last(slist_t **head, int data)
{
	if(*head == NULL)
	{
		*head = create_node(data);
	}
	else
	{
		slist_t *ptr = *head;

		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		slist_t *new = create_node(data);
		ptr->next = new;
	}
}//insert_last

void print_list(slist_t **head)
{
	slist_t *ptr =*head;
	while(ptr != NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void delete_first(slist_t **head)
{
	if(*head ==NULL)
		printf("List is empty");
	slist_t *ptr=*head;
	*head=(*head)->next;
	free(ptr);
}

void delete_last(slist_t **head)
{
	slist_t *prev;	//the last-but-one element should be Made NULL hence we use prev
	slist_t *ptr = *head;
	if(*head ==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if((ptr)->next == NULL)	//if there is only 1 element.
	{
		free(ptr);
		*head=NULL;
	}
	else
	{	
		while(ptr->next !=NULL)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		free(ptr);
		prev->next = NULL;
	}
}

void delete_list(slist_t **head)
{
	slist_t *prev=*head;  //in slist prev is just another pointer.
	slist_t *ptr = *head;
	while(ptr !=NULL)
	{
		prev=ptr;
		ptr= ptr->next;
		free(prev);
	}
	*head=NULL;
	//free(prev);//gives double free error. or corruption (fast top) Core-Dumped.
	//free(*head);gives error when you try to del the list @nd time and the deleted value will be displayed as 0 hence *head=NULL is Correct
}
/*
   void delete_ele(slist_t **head, int data)
   {
   int found=0;
   slist_t *ptr = *head;
   slist_t *prev=*head;

   while(ptr->next != NULL)
   {

   if(ptr->data == data)
   found=1;
   if(found)
   ptr->data = (ptr->next)->data;
   prev = ptr;
   ptr=ptr->next;   
   }
   free(ptr);
   prev->next = NULL;
   }
 */

void delete_ele(slist_t **head, int data)	//to delete a particular element.
{
	slist_t *ptr=*head;
	slist_t *prev=*head;
	if((*head)->data == data)
	{
		delete_first(head);
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			if(ptr->data != data)
			{
				prev=ptr;
				ptr=ptr->next;
			}
			else
			{
				if(ptr->next == NULL)
				{
					delete_last(head);
					return;
				}
				else
				{
					prev->next=ptr->next;
					free(ptr);
				}
			}

		}
		printf("Element not in the list\n");
	}
	//printf("Element not in the list\n");

}

void mid(slist_t **head)	//Assignment 5.
{
	slist_t *fast = *head;
	slist_t *slow = *head;

	while( (fast->next != NULL) && (fast->next->next != NULL) ) //fast->next is for ODD fast->next->next is for Even.
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("Middle ele is %d\n",slow->data);

}
void find(slist_t **head)	//Assignment 5.
{
	int n;
	slist_t *ptr = *head;
	printf("Enter the ele you want to find\n");
	scanf("%d",&n);
	while(ptr != NULL)
	{
		if(ptr->data == n)
		{
			printf("Ele %d was found\n",n);
			return;
		}
		else
		{
			ptr=ptr->next;
		}
		//printf("%d\t",ptr->data);
	}
	printf("Element not found\n");
}

/*
   void insert_before(slist_t **head,int data)	//Assign 2.
   {
   int bdata;
   slist_t *ptr=*head;
   slist_t *prev=*head;
   printf("Enter the Data BEFORE which you want to enter the New Data\n");
   scanf("%d",&bdata);
   if (*head == NULL)
   {
   printf("The list is Empty\n");
   return;
   }
   if((*head)->data == bdata)
   {
   insert_first(head,data);
   return;
   }
//else
//{


while(ptr != NULL)
{
if(ptr->data != bdata)
{
prev=ptr;
ptr=ptr->next;
}
else if(ptr->data == bdata)
{
slist_t *new = create_node(data);
prev->next = new;
new->next = ptr;
}
}//while
//}
}
 */

//INSERT BEFORE.
void insert_before(slist_t **head,int data)	//Assign 2.
{
	int bdata;

	printf("Enter the Data BEFORE which you want to enter the New Data\n");
	scanf("%d",&bdata);
	if (*head == NULL)
	{
		printf("The list is Empty\n");
	}
	else
	{
		if(bdata == (*head)->data)
		{
			insert_first(head,data);
		}
		else
		{
			slist_t *ptr = (*head)->next;
			slist_t *prev = *head;
			while(bdata != ptr->data)
			{
				prev = ptr;
				ptr = ptr->next;
				if(prev->next == NULL)		//prev->next not ptr->next
				{	
					printf("Element before which you want to Enter is not found in the List.\n\n");
					return;
				}	
			}

			slist_t *new = create_node(data);
			prev->next = new;
			new->next = ptr;
		} // 2nd if and else.

	}//1st if and else

}

//INSERT AFTER
void insert_after(slist_t **head, int data)
{
	if(*head == NULL)
	{
		insert_last(head,data);
	}
	else
	{
		int adata;
		slist_t *ptr = *head;
		slist_t *prev = *head;
		printf("Enter the Data AFTER which you have to insert the element\n");
		scanf("%d",&adata);

		if(adata == (*head)->data)	//if the data is at the beginning or at head position.
		{
			ptr=ptr->next;
			slist_t *new = create_node(data);
			(*head)->next = new;
			new->next = ptr;
		}
		else
		{
			while(adata !=ptr->data)
			{
				prev=ptr;
				ptr=ptr->next;
				if(prev->next == NULL)		//prev->next not ptr->next Error Handling.
				{	
					printf("Element after which you want to Enter is not found in the List.\n\n");
					return;
				}	
			}
			ptr = ptr->next;
			prev=prev->next;
			slist_t *new = create_node(data);
			prev->next=new;
			new->next=ptr;
		}
	}
}

void insert_nth(slist_t **head)
{
	int data,pos,count = 1;
	slist_t *ptr = *head;
	slist_t *prev = *head;

	printf("Enter the data\n");
	scanf("%d",&data);

	printf("Enter the POSTION before which you wan to enter the new Element\n");
	scanf("%d",&pos);

	if(*head == NULL)
	{
		insert_first(head,data);
	}
	else
	{
		while(count != (pos+1))	//pos +1 cos we are using 2 pointers and replacing the prev->data in the new Pointer.
		{
			count++;
			prev=ptr;
			ptr=ptr->next;
		}
		slist_t *new = create_node(prev->data);
		prev->data = data;
		prev->next = new;
		new->next = ptr;
	}
}

void nth_from_last(slist_t **head)
{
	int length = 0,pos,i;
	printf("Enter the pos from last\n");
	scanf("%d",&pos);
	slist_t *ptr=*head;
	slist_t *prev=*head;
	if(*head == NULL)
	{
		printf("The Lsit is Empty\n");
		return;
	}
	while(ptr != NULL)
	{
		length++;
		ptr=ptr->next;
	}
	printf("The lenght is %d\n",length);

	if(pos > length)
		printf("Postion not found\n");

	for(i=0;i<length-pos;i++)		//LENGTH - POSITION.
	{
		prev=prev->next;
	}
	printf("The data is %d\n",prev->data);
}


void create_loop(slist_t **head)
{
	slist_t *ptr=*head;
	if(*head == NULL)
	{
		printf("The List is Empty\n");
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		if(ptr->next == NULL)
		{
			ptr->next = (*head);
			printf("It is Circular\n");
		}
	}
}

void find_loop(slist_t **head)
{
	if(*head == NULL)
		printf("NO list\n");   
	else
	{
		slist_t *slow=*head;
		slist_t *fast=*head;
		while(slow != NULL && fast != NULL && fast->next != NULL)
		{
			// if it is not a loop then fast->next != NULL condtion would be Used. other-wise core-dump.
			slow=slow->next;
			fast=fast->next->next;
			if(slow == fast)
			{
				printf("It is a LOOP\n");
				return;
			}
		}
		printf("It is Not a LOOP\n");
	}
}


void insert_sorted(slist_t **head,int data)
{
	slist_t *ptr=*head;

	if (*head == NULL)
		*head = create_node(data);
	while(ptr!= NULL)
	{
		if (data < (*head)->data)
			insert_first(head,data);

		if (ptr->data < data && ptr->next == NULL)
			insert_last(head,data);

		else if( (ptr->data < data) && (ptr ->next -> data > data) )	//20 < 25 && 30 > 25 
		{	
			slist_t *new = create_node(data);
			new->next=ptr->next;
			ptr->next=new;
		}
		else
			ptr=ptr->next;
	}
}

void reverse_itr(slist_t **head)
{
	slist_t *ptr=*head;//10
	slist_t *prev=NULL;
	slist_t *nexxt=NULL;
	if(*head == NULL)
		printf("No List\n");
	else
	{
		while(ptr != NULL)
		{ // 10 20 30
			nexxt=ptr->next;//20  will pointing to the 2nd data.
			ptr->next=prev;//1st time iti is made null. prev will be null for 1st time
			prev=ptr;//10 prev would be changed here. we should not use prev->next = ptr they both will be linked and leads to SEg FAult. we are assigning prev to the loc of ptr We are not Linking them.
			ptr=nexxt;//20
		}
		*head=prev;// after the while loop breaks, ptr will be Out of the loop and we assign head to prev.
	}

}


void reverse_recur(slist_t *head)
{
	slist_t *ptr = head;
	if(ptr != NULL)
	{
		ptr = ptr->next;
		//		(*head)=(*head)->next;
		reverse_recur(ptr);
		printf("%d\n", (head)->data);
	}
}

void sort(slist_t ** head)	//bubble sort.
{
	int temp = 0;   //initialization
	slist_t *ptr = *head;
	if(*head == NULL)
		printf("list is empty\n");
	else
	{
		while(ptr->next != NULL)	//1st for loop with ITERATIONS
		{
			slist_t *ptr1 = *head;
			while(ptr1->next != NULL)	//FOR LOOPING in the loop.
			{
				if(ptr1->data > ptr1->next->data)	//a[j] amd a[j+1]
				{
					temp = ptr1->data;
					ptr1->data = ptr1->next->data;
					ptr1->next->data = temp;
				}
				ptr1 = ptr1->next; //j++
			}
			ptr = ptr->next;//i++
		}
	}
}

void remove_duplicates(slist_t **head) //function call
{
	if(*head == NULL)
		printf("list is empty\n");  //if list is empty then print error message
	else
	{
		slist_t *ptr = *head;  //assign head to ptr
		slist_t *temp;
		while(ptr->next != NULL)  //check till next condition
		{
			if(ptr->data == ptr->next->data)  //if data is found
			{
				if(ptr->next->next == NULL)	//if data isin the last position.
				{
					ptr->next = NULL;//Instead of delete_last Just Assign ptr->next to NULL. 
					return;
				}
				temp = ptr->next;//the ele we want to free is stored on temp.
				ptr->next = ptr->next->next;//ptr->next is linked with ptr->next->next
				free(temp);
			}
			else
				ptr = ptr->next;  //point ptr to next condition
		}
	}
}

  
