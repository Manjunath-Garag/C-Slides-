#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_function(void *arg);
int glob;

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, &thread_function, NULL);//on success returns 0
	//created a thread for the function which will be cancled later.

	if(res != 0)
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}
	sleep(3);

	printf("Cancelling thread");
	res = pthread_cancel(a_thread);
	if(res != 0)
	{
		perror("Thread Cancellation failed");
		exit(EXIT_FAILURE);
	}
	pthread_join(a_thread, NULL); //to clear the stack.
	printf("glob = %d\n",glob);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	int i , res;
	glob = 111;
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); //1st parameter is a Macro. ENABLED
	//res = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL); //Cancel is disabled. returns '0' on Success

	if(res != 0)
	{
		perror("Thread pthread_setcancelstate failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread still runnning\n");
	for(i=0; i<10; i++)
	{
		printf("\n Thread function is running (%d)...\n",i);
		sleep(1);
	}
	pthread_exit(0);
}

/*
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/threads$ gcc cancelstate.c -lpthread
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/threads$ ./a.out 
Thread still runnning

 Thread function is running (0)...

 Thread function is running (1)...

 Thread function is running (2)...
Cancelling threadglob = 111

*/

