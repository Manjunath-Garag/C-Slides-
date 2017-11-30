#include<stdio.h>
#include<unistd.h>

int g;
int main()
{
	int val;
	val = fork();
	if(val == 0)
	{
		printf("Hello child\n");
		sleep(2);
	}
	else
	{
		printf("World parent\n");
		sleep(2);
	}
	printf("Bahubali\n");

}
