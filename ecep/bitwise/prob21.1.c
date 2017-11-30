#include<stdio.h>

int main()
{
	static int n,first=0,second=1,c=0,res=0; // all are in the Data Segment.


	if(c==0) // this executes only once.// since 'c' is STATIC.
	{
		printf("Enter a Number:\n");
		scanf("%d",&n);
		printf("%d\n",first);
	}
	else if(c==1)
	{
		printf("%d\n%d\n",first,second);
	}	
	else

		if(res<=n)
		{
			res=first+second;
			first=second;
			second=res;


			if(res<=n)// again the condtion is checked.
				printf("%d\n",res);

			main();
		}


	return 0;
}
