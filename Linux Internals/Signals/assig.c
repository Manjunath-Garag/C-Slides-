#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

void handler (int arg)
{
	static int count = 0;
	if(arg == SIGINT)
	{
		count++;
		//printf("Count is %d\n",count);
		printf("sigint was called used for %d\n",count);
	}
	if(count == 7)
	{
		exit(0);
	}
}

int main()
{
	signal(SIGINT,handler);
	while(1);
}

