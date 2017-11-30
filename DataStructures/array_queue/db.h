#ifndef DB_H
#define DB_H

typedef struct student
{
	char name[20];
	double ph_no;
	char mail[20];
int fees;
	struct student *next;
}db;

db *create_nodedb(char *name, double ph_no, char *mail,int fees);
void insert_nodesdb(db **head, char *name, double ph_no, char * mail,int fees);
void print_detailsdb(db **head,FILE *fp);
void fee_due(db **head);

#endif
