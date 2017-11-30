#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<hotel.h>

int hash(char *key)
{
	char ch = *key;
	if(isupper(ch))
	{
		ch = tolower(ch);
	}
	return (ch - 97);
}


int main()
{
	char name[30];
	char loc[30];
	int tables, capacity;
	struct *ptr[26] = {0};
	while(1)
	{
		printf("Enter your choice\n 1 :Add Rest\n 2 :Search Rest\n 0 : exit\n");
		switch(choice)
		{
			case 1 : 
				printf("Enter the name , loc , no of tables , capacity \n");
				scanf("%s %s %d %d",name,loc,&tables, &capacity);

				if(&ptr[hash(name)] == NULL)
					ptr[hash(name)] = create_hotel(name, loc, tables, capacity);
				else
					insert_hotel(&ptr[hash(name)], name, loc, tables, capacity);

				break;


		}//switch
	}//while
}//main
