#include<stdio.h>

int main()
{
	int i,line=1;
	char ch;
	char charcount=0, word=1;
	printf("Enter the String.");

	while ( (ch=getchar()) !=EOF)//Double Braces. Percedence (ch=getchar()) is solved first.
	{
		if(ch=='\n')
		{
			++line;
		}

		if(ch!='\0')
		{
			++charcount;
		}
		if(ch==' ' || ch == '\n')
		{
			++word;
		}

	}		
	printf("\nline count:%d\n",line);
	printf("char count:%d\n",charcount);
	printf("word count:%d\n",word);


	return 0;
}
