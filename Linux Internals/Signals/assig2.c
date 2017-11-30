#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int flag,count;

void handler (int arg)
{
	if(arg == SIGINT)
	{
		flag=1;
	}
}


int main()
{

	signal(SIGINT,handler);
	while(1)
	{
		if(flag)
		{
			count++;
			if(count == 7)
				exit(0);
			printf("%d times signal was received\n",count);
				flag=0;
		}
	}
}
