#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

void handler(int arg)
{
	printf("Alaram Siganl was sent\n");
}

int main()
{
	signal(SIGALRM,handler);	//Regestration is done.
	alarm(5);
	while(1);	//keeps executing until a alarm signal is raised.
}

