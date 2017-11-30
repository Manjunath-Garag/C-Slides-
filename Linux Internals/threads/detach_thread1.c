#include<stdio.h>
#include<pthread.h>

/*
To detach a Normal thread 1st we need to create a thread in the pthread_create() function we need to set the second attribute.
which is a constant variable, const pthread_attr_t 
the Const Variable has to be defined then it has to be initialized
Then the Initialized value has to be set using some function called setdetachstate( thread_id, macro);
*/

void * thread_function(void * thread_arg)
{
	int i = 10000;
	while(i--)
	{
		fputc('A', stderr);
	}
}

int main()
{
	pthread_attr_t attr;  //2nd attribute in pthread_create()
	pthread_t thread;	//a thread is created to store the Thread_id.
	pthread_attr_init (&attr);	//Initializing all the attribute to some value(say 0)
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);	//CREATING A DETACHABLE THREAD. SETING

/* detach clears the Stack Automatically and nothing should be returned from the thread_function 
"NO return" value should be there for detach_attr */

	pthread_create(&thread, &attr, &thread_function, NULL);

	sleep(1);
	//pthread_attr_destroy(&attr) //this is to Re-use the Attribute for another thread. Each time Memory is cleared. and a new thread  is  generated.
	while(1);
		/* NO need to join the thread Cos Detach functionality Automaticlly clears the Stack*/
		return 0;
}


/*
Other attributes for 2nd Parameter.
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/threads$ man pthread_attr_set  (press tab)
pthread_attr_setaffinity_np   pthread_attr_setinheritsched  pthread_attr_setscope         pthread_attr_setstacksize
pthread_attr_setdetachstate   pthread_attr_setschedparam    pthread_attr_setstack         
pthread_attr_setguardsize     pthread_attr_setschedpolicy   pthread_attr_setstackaddr    

emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/threads$ man pthread_attr_get
pthread_attr_getaffinity_np   pthread_attr_getinheritsched  pthread_attr_getscope         pthread_attr_getstacksize
pthread_attr_getdetachstate   pthread_attr_getschedparam    pthread_attr_getstack         
pthread_attr_getguardsize     pthread_attr_getschedpolicy   pthread_attr_getstackaddr 
*/
