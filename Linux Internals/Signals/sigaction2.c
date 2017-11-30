#include<stdio.h>
#include<string.h>
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

void sa_handler2(int arg, siginfo_t *info, void *not_used)
{
printf("signal sent from %d\n",info->si_pid);//2618 is generated from here. (that Signal was from bash)
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

	//this is for 1st handler //act.sa_handler = handler;//accessing the attribute from the Structure. man 2 sigaction structure.
	//calling sigaction function.

	act.sa_sigaction = sa_handler2;
	//set flag to enable 2nd argument of the handler.

	act.sa_flags = SA_SIGINFO;//this is a must to access the 2nd argument

	sigaction(SIGINT, &act, &oldact/* 3rd arg can be NULL*/);
	printf("pid is %d\n",getpid());

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


/*

TERMINAL 1:
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ ./a.out 
pid is 2634
signal sent from 2618
1 times signal was received
signal sent from 2618
2 times signal was received
signal sent from 2618
3 times signal was received
signal sent from 2618
4 times signal was received
signal sent from 2618
5 times signal was received
signal sent from 2618
6 times signal was received
signal sent from 2618


TERMINAL 2 ::this done to use the sa_handler2
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ kill -2 2634
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ kill -2 2634
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ kill -2 2634
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ kill -2 2634
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ kill -2 2634
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ kill -2 2634
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/signals$ kill -2 2634

from ps -el
  1000  2618  2244  0  80   0 -  1727 wait_w pts/17   00:00:00 bash

*/
