#include<stdio.h>

int main()
{
	static int n,first=0,second=1,c=0,res=0; // all are in the Data Segment.

	c++;// to execute it we make use of the below cond and the varaible 'c'

	if(c==1) // this executes only once.
	{
		printf("Enter a Number:\n");
		scanf("%d",&n);
		printf("%d\n%d\n",first,second);
	}
	

	if(res<n)
	{
		res=first+second;
		first=second;
		second=res;


		if(res<=n)// again the condtion is checked.Cos the result would be changed. this would be applied if the above if cond was  (res <=n)
			printf("%d\n",res);

		main();
	}


	return 0;
}
