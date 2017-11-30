#include<stdio.h>
//iterate it Manually.
int main()
{
	static int n,r=1,c=0; // all are in the Data Segment.

	c++;

	if(c==1) // this executes only once.
	{
		printf("Enter a Number:\n");
		scanf("%d",&n);
	}

	if(n!=0)
	{
		r=r*n;
		n--;

		main();
		c--;
	}

	if(c==1)// this value can be anything cos the ithas execute only once.1,2,3,...
		printf("Factorial is %d \n",r);

	return 0;
}
