#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev,*next;

}dlist_t;

dlist_t *dl_create_node(int data)	//creating new Struct.
{
	dlist_t *new = malloc(sizeof(dlist_t));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void dl_insert_first(dlist_t **head, int data)
{
	if(*head == NULL)
	{
		*head = dl_create_node(data);	//if head is Null, we create a new node and add the Data.
	}
	else		//else if a data is added In-between, and change the nodes.
	{
		dlist_t *new = dl_create_node(data);
		new->next = *head;
		(*head)->prev =new;
		*head = new;
	}

}

void dl_insert_last(dlist_t **head, int data)
{
	if(*head == NULL)
	{
		*head = dl_create_node(data);	// if head is NULL , we create a anew Node.
	}
	else
	{
		dlist_t *ptr = *head;
		while(ptr->next != NULL)	//this while loop will take you to the last element in the List.
		{
			ptr=ptr->next;
		}
		dlist_t *new =dl_create_node(data);
		new->prev = ptr;
		ptr->next = new;
	}

}

void dl_delete_first(dlist_t **head)
{
	dlist_t *ptr = *head;
	if(*head == NULL)
	{
		printf("NO element in the list\n");
		return;
	}
	else
	{
		while(ptr->next != NULL)	//Checks if next ATTRIBUTE is Null or not.
		{
			*head = ptr-> next;		//to free the 1st element and change the Head.
			free(ptr);	
			(*head)->prev = NULL;

			//free(ptr);	
		}
		if((*head)->next == NULL)
		{
			free(ptr);	//free's the First element, if It is the Only element Present.
			*head = NULL;	//head is not made null or becomes a Dangling Pointer. If this line is Commented then the deleted element would be replaced with 0 , and sometimes might affect Other Functions as well.
		}
	}
}

void dl_delete_last(dlist_t **head)
{
	if(*head == NULL)
	{
		printf("NO element in the list\n");	
		return;
	}
	else
	{
		dlist_t *ptr = *head;
		if(ptr->next == NULL)	// will check if the pointer is NULL or not.
		{
			free(ptr);
			*head = NULL;
		}
		else
		{
			while(ptr->next != NULL)
			{
				ptr=ptr->next;
			}

			(ptr->prev)->next = NULL; // make the previous elments NEXT-ATTRIBUTE should be made NULL.

			//freeing the last (ptr->prev :: will point to the whole structure, hence) (ptr->prev)->next:: will point to the next part and make only the next part ZERO.


			free(ptr); //then free ptr. this line can be avoided Since in line 104 we are making the next attribute as NULL.
		}
	}
}

void dl_delete_list(dlist_t **head)
{
	if(*head == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	else
	{
		dlist_t *ptr = *head;
		while(ptr->next != NULL)	//this will Take you to the last-but-onr Element.
		{
			ptr= ptr->next;	//ptr is changed or Incremented.
			*head=ptr;	//head is changed
			free(ptr->prev);	// since head is changed we free PREV Struct.

		}
		free(ptr);	//this will Free the last element.
		*head=NULL;

	}
}


void dl_print_list(dlist_t **head)
{
	dlist_t *ptr =*head;
	while(ptr != NULL)	//Prints untill last element.
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void dl_insert_after(dlist_t **head,int data)
{
	int adata;
	dlist_t *ptr = *head;
	printf("Enter the data AFTER which You want to Insert\n");
	scanf("%d",&adata);
	if(*head == NULL)
	{
		printf("No list avail\n");
		return;
	}
	else if( (adata == ptr->data) && (ptr->next == NULL))	//if there is only one element in the List.
	{
		dl_insert_last(head,data);
		return;
	}
	else
	{
		while(ptr->data != adata)	// Data Not found.
		{		
			ptr= ptr->next;		//increment the ptr.
			if(ptr == NULL)
			{
				printf("Element not found\n");	// If element not found PTR would be a Dangling Pointer.
				return;
			}
		}
		if(ptr->next == NULL)	//inserts after the last elemenet.
		{
			dl_insert_last(head,data);
			return;
		}
		else
		{
			dlist_t *new = dl_create_node(data);
			//	printf("hi\t");
			new->prev = ptr;
			new->next = ptr->next;
			ptr->next->prev = new;
			ptr->next = new;
		}

	}//else
}


void dl_insert_before(dlist_t **head, int data)
{
	int bdata;
	dlist_t *ptr = *head;
	printf("Enter the Data BEFORE which it has to be Inserted\n");
	scanf("%d",&bdata);
	if(*head == NULL)
	{
		printf("No list Avail\n");
	}
	else if(bdata == ptr->data)	// for thefirst data.
	{
		dl_insert_first(head,data);
	}
	else
	{
		dlist_t *new = dl_create_node(data);
		while(bdata != ptr->data)	//to find the Data.
		{
			ptr=ptr->next;
			if(ptr == NULL)
			{
				printf("Element not found\n");
				return;
			}
		}
		new->prev = ptr->prev;	
		new->next = ptr;
		ptr->prev->next = new;
		ptr->prev = new;

	}//2nd if else

}


void dl_delete_ele(dlist_t **head, int data)
{
	dlist_t *ptr = *head;
	if(*head == NULL)
	{
		printf("List is empty\n");
		return;	//exit(1);
	}
	else if(ptr->data == data)		//if data is Found at the Head.
	{
		dl_delete_first(head);
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			if( (ptr->data == data) )	//This will help you delete the Ubtilthe last-but-one ELE.
			{
				if(ptr->next == NULL)	//this is for Last element.
				{
					dl_delete_last(head);
				}
				else
				{
					(ptr->prev)->next = ptr->next;
					(ptr->next)->prev = ptr->prev;
					free(ptr);
				}				
				return;
				break;
			}
			else
			{
				ptr=ptr->next;
				if(ptr == NULL)
				{
					printf("Ele not found\n");
					return;
				}
			}
		}
	}
}
