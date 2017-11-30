#include<stdio.h>

int main()
{
	int i,count=0;
	char array[100],ch;
	printf("Enter the String.");
//	scanf("%[^]",array);// it works fine without 's'as well.
	while (ch=getchar()!=EOF)
{
//Char Count.
	for(i=0;i<100;i++)
	{
		if(array[i] != '\0')
		{
			++count;
		}
		else
		{
			break;
		}
	}
	printf("Char count:%d\n",count);

}
	return 0;
}
