#include<stdio.h>
int main()
{
	int  cc=0,wc=0,temp=0,lc=1;
	char ch;
	printf("enter the string\n");

	while((ch=getchar())!=EOF)
	{
		cc++; //char count

		if(ch!=' ' && ch!='\n' && ch!= '\t')
		{
			temp++; //char count.

		}
		else if(ch=='\n') // if it goes to next line.
		{
			lc++;
			if(temp>0) //If char count is >0 word count is incremented.
			{
				wc++;
				temp=0;// then again initialze theword count and start it form the beginning for the next word.
			}
		}
		else // this cond is for one line without \n
		{

			if(temp > 0)
			{
				wc++;
				temp=0;
			} 
		}

	}

	//while finished      

	if(temp > 0)
	{
		wc++;
		temp=0;
	} 

	printf("\nno.of char:%d",cc);
	printf("\nno.of words:%d\n",wc);
	printf("\nno.of lines:%d\n",lc);
	return 0;
}

