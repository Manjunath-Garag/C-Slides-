#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	char name[20];//static allocation.
	int age;
	double phone_no;
	struct node *next;
}node_t;


node_t *create_nodes( char *name,int age,double phone_no)	//we are just creating a structure here.
{
	node_t *new = malloc(sizeof(node_t));

	//	new->name = name;
	strcpy(new->name , name);	//has to be copied, to that loc.
	new->age=age;
	new->phone_no=phone_no;
	new->next=NULL;
	return new;	//returns the address.
}


node_t  insert_nodes(node_t **head, char *name,int age,double phone_no)//like inser_last.
{

	/*	if(alpha[hash(name)] == NULL) //a[0] == NULL
		{
		arr[hash(name)] = create_nodes(name,age,phone_no);
		return head;
		}
		else
		{ 	//THIS PART IS WRITTEN IN MAIN. 
	 */
	node_t *ptr = *head;	//ptr is pointing to the structure.
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	node_t *new = create_nodes(name,age,phone_no);
	ptr->next=new;

}

void print_nodes(node_t **head)		//to print particular element.
{
	node_t *ptr =*head;
	while(ptr != NULL)
	{
		printf("%s\t",ptr->name);
		ptr=ptr->next;
	}
	printf("\n");
}


void delete_nodes(node_t **head,char *data)
{
	node_t *ptr=*head;
	node_t *prev=*head;
	printf("the data you want to delete is : %s\n",(*head)->name);

	if(!strcmp((*head)->name,  data))	//just like : if((*head)->name == data)
	{
		(*head) = (*head)->next;
		free(ptr);
		return;
	}
	else
	{
		while(strcmp(ptr->name, data))	//while(ptr->name != data)
		{	
			prev=ptr;
			ptr=ptr->next;
		}
		if(ptr->next == NULL)//if that is the last node.
		{
			free(ptr);
			prev->next=NULL; return;
		}
		else
		{
			prev->next = ptr->next;
			free(ptr);
	}
	}
}


void search_nodes(node_t **head,char *data) //accepting &arr[hash(name)]
{
	node_t *ptr = *head;
	//printf("%s",data);
	while(strcmp(ptr->name,data))
	{	
		ptr=ptr->next;
	}
	if(ptr->next == NULL)
	{
		printf("NO details\n");
		return;
	}
	printf("Name:%s\n",ptr->name);
	printf("Age:%d\n",ptr->age);
	printf("Ph no:%.lf\n",ptr->phone_no);
}

void print_details(node_t *head)	//to print arr[i] 
{
	node_t *ptr = head;
	if(head ==  NULL)
	{
		printf("The List is Empty\n");
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			printf("Name:%s\n",ptr->name);
			printf("Age:%d\n",ptr->age);
			printf("Ph no:%.lf\n",ptr->phone_no);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void delete_table(node_t **head)
{
	node_t *prev= *head;  //in slist prev is just another pointer.
	node_t *ptr = *head;
	while(ptr != NULL)
	{
		prev=ptr;
		ptr= ptr->next;
		free(prev);
	}
	//free(head);
	*head=NULL;
}
