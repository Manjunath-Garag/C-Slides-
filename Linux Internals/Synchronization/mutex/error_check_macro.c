#include<errno.h>
#include<stdio.h>
#include<pthread.h>

//pthread_mutex_t mutex;
pthread_mutex_t mutex = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;

void fun(void);
void *thread_func(void *args)
{
	printf("%lu locking mutex\n",pthread_self());
	pthread_mutex_lock(&mutex);
	printf("%lu locked mutex\n",pthread_self());
	fun();
	sleep(2);
	pthread_mutex_unlock(&mutex);
}
void fun(void)
{
	if(pthread_mutex_lock(&mutex) == 35 /* EDEADLOCK 35 is the no of this Macro*/)
	{
		printf("! (%lu) already locked the mutex \n",pthread_self());
	}
}
int main()
{
	pthread_t tid1,tid2,tid3;
/*
	pthread_mutexattr_t attr;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setkind_np(&attr, PTHREAD_MUTEX_ERRORCHECK);// seting  //comment and see the OP.
	pthread_mutex_init(&mutex, &attr);
*/
	pthread_create(&tid1, NULL, thread_func, NULL);		//thread_func and &thread_func are send the same address.
	pthread_create(&tid2, NULL, thread_func, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}

/*
   emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/synch$ ./a.out 
   Taking a Lock 3076455232
   Taking a Lock 3076455232
   Taking a Lock 3076455232
   releasing lock 3076455232
   releasing lock 3076455232
   Taking a Lock 3076455232
   releasing lock 3076455232
   releasing lock 3076455232
   Taking a Lock 3068062528
   Taking a Lock 3068062528
   Taking a Lock 3068062528
   releasing lock 3068062528
   releasing lock 3068062528
   Taking a Lock 3068062528
   releasing lock 3068062528
   releasing lock 3068062528

 */

