#include<stdio.h>
#include<stdlib.h>
#include<db.h>

int hash(char *key)
{
	char ch = *key;
	if(isupper(ch))
	{
		ch = tolower(ch);
	}
	return (ch - 97);
}

void main()
{
	FILE *fp;
	fp = fopen("db.txt","w");
	db *ptr[26] ={0};
	int choice;
	char name[20];
	char mail[20];
	double ph_no;
	int fees;
	int res;

	while(1)
	{
		printf("0: Exit\n1 : Enter db\n2 : Del table\n3 : Del Name\n4 : Print List\n5 : Calculate Due Amount\n");
		__fpurge(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			int i;
			case 0 : exit(0);
			case 1 :
				 printf("Enter Student Name, Ph_no, mail-id, fees\n");
				 scanf("%s %lf %s %d",name, &ph_no, mail,&fees);
				 res = hash(name);
				 if(ptr[res] == NULL)
					 ptr[res] = create_nodedb(name, ph_no, mail,fees);
				 else
					 insert_nodesdb(&ptr[res], name, ph_no, mail,fees);
				 break;

			case 4 : 
				 fprintf(fp,"NAME\t\t" "Ph.No\t\t" "Mail-id\n\n");
				 for(i=0;i<26;i++)
					 print_detailsdb(&ptr[i],fp);
				 break;
			case 5 :
				 for(i=0;i<26;i++)
					 fee_due(&ptr[i]);
				 break;


		}
	}
}
