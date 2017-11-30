#include<stdio.h>
//in this program we are making use of both pass by ref and pass by value.


int pre(int *ptr);

int main()
{
	int temp,n,n2,i,j;
	printf("Enter a number\n");
	scanf("%d",&n);
	
	n2=n;
	temp=n2;
	j=post(&n2);
	i=pre(&n);
	printf("Pre: i=%d num=%d\n",i,n);
	printf("Post: i=%d num=%d\n",temp,n2);
	return 0;
}

int pre(int *ptr)// pass by ref
{
	int mask=1;

	while(mask & (*ptr)) // if the no is 1, It enter the while loop.
	//this is done until the number is 0
	{
		(*ptr)=(*ptr)^mask;// then the no os Toggled. 
		mask=mask<<1;
	}
	(*ptr)=(*ptr)^mask;// once it encounters a ZERO That has to be TOggled.
	//return 0;
	return (*ptr);// we can not return 0 because the pre function is loaded to an int i, which is again ecpecting a value.
	// the above ret we make use of pass by value.
}


int post(int *ptr)// pass by ref
{
	int mask=1;

	while(mask & (*ptr))
	{
		(*ptr)=(*ptr)^mask;
		mask=mask<<1;
	}
	(*ptr)=(*ptr)^mask;
	//return 0;
	return (*ptr);// we can not return 0 because the pre function is loaded to an int i, which is again ecpecting a value.
	// the above ret we make use of pass by value.
}


/*

0001
0010


0011
0100

*/
