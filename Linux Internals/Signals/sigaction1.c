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
	//signal(SIGINT,handler);  //signal

	struct sigaction act,oldact;	//making use ofthat structure(Creating that Object)

	memset(&act, 0, sizeof(act));//making allthe variables of act to ZERO.

	act.sa_handler = handler;//accessing the attribute from the Structure. man 2 sigaction structure.
	//calling sigaction function.

	sigaction(SIGINT, &act, &oldact/* 3rd arg can be NULL*/);

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
