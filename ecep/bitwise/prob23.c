#include<stdio.h>

int main()
{

	while (1)
	{
		char str[100];

		int i,flag=1; 
		printf("Enter the string:");
		scanf("%[^\n]",str); // accepts the char untill the \n charcter.

		for(i=0;str[i]!='\0';i++)
		{
			if((str[i]==' '|| str[i]=='\t') && flag)
			{
				printf(" ");
				flag=0;
			}

			if(str[i]!=' ' && str[i]!='\t') // && is the Operator,If both condtions are ture then it would be an Alphabet.
			{
				printf("%c",str[i]);
				flag=1;// once it encounters an Alphabet the flag is initialized to 1.
			}
		}
		printf("\n");
		getchar(); // IMP.
		printf("Do you want to Continue y/n\n");
		char ch =getchar();

		__fpurge(stdin);

		if(ch=='n' || ch=='N')
			break;

	}//while
	return 0;
}
