#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student 
{
	char name[20];
	double ph_no;
	char mail[20];
	int fees;
	struct student *next;
}db;

db *create_nodedb(char *name, double ph_no, char *mail, int fees)
{
	db *new = malloc(sizeof(db));
	strcpy(new->name, name);
	strcpy(new->mail, mail);
	new->ph_no = ph_no;
new->fees = fees;
	new->next = NULL;
	return new;
}

void insert_nodesdb(db **head, char *name, double ph_no, char * mail,int fees)
{
	db *ptr = *head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	db *new = create_nodedb(name,ph_no,mail,fees);
	ptr->next = new;
}

void print_detailsdb(db **head,FILE *fp)
{
	db *ptr = *head;
	if(*head == NULL)
	{
		//		printf("List is empty\n");
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			fprintf(fp,"%s\t\t%.lf\t\t%s\n",ptr->name,ptr->ph_no,ptr->mail);	//Moving the data here itself.
			printf("%s\t",ptr->name);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void fee_due(db **head)
{
int total_fees = 30000;
	db *ptr = *head;
	if(*head == NULL)
	{
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			printf("%s\t%d\n",ptr->name,ptr->fees);
			printf("due: %d\n",total_fees - (ptr->fees));
			ptr=ptr->next;
		}
		printf("\n");
	}
}

