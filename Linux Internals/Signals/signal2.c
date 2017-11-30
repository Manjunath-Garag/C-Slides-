#include<stdio.h>
#include<signal.h>

void handler(int arg)
{
	if(arg == SIGINT)
		printf("sigint signal was received\n");
	else if(arg == SIGQUIT)
		printf("sigquit signal was received\n");
	else
		printf("Unkown signal was received\n");
}

int main()
{
	signal(SIGINT,handler);
	signal(SIGQUIT,handler);
	while(1);
}

