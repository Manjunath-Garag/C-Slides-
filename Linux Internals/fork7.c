#include<stdio.h>
#include<unistd.h>

int g;
int main()
{
	int x=10;
	int val;
	val = fork();
	if(val == 0)
	{
		x++;
		g++;
		printf("Child:%d %d\n",x,g);
		sleep(2);
	}
	else
	{
		x++;
		g++;
		printf("Parent:%d %d\n",x,g);
		sleep(2);
	}
}
