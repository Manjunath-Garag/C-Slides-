#include<stdio.h>
#include<unistd.h>

//in this code both printf statments are executed.
//both are printed in different positions.

int main()
{
	int val, i;
	val = fork();
	if(val == 0)
	{
		printf("Hello");	//child
		for(i=0; i<100; i++)
		{
			printf("INSIDE CHILD\n");
			sleep(2);
		}
	}
	else
	{
		printf("World\n");	//parent 
		for(i = 0; i<100; i++)
		{
			printf("Inside Parent\n");
			sleep(6);
		}
	}
}

