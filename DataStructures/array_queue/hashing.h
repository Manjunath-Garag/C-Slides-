#ifndef HASHING_H
#define HASHING_H

typedef struct node
{
	char name[20];
	int age;
	double phone_no;
	struct node *next;
}node_t;
node_t *create_nodes(char *name,int age,double phone_no);
node_t insert_nodes(node_t **head,char *name,int age,double phone_no);
node_t  insert_nodes(node_t **head,char *name,int age,double phone_no);
void delete_nodes(node_t **head,char *data);

void print_details(node_t *head);
void delete_table(node_t **head);

#endif
