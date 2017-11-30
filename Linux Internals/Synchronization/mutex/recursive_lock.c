#include<stdio.h>
#include<pthread.h>
void *thread_func(void *args);

pthread_mutex_t mutex;

void fun(int a)
{
	pthread_mutex_lock(&mutex);
	printf("Taking a Lock %lu\n",pthread_self());
	while(a > 0)
	{
		fun(--a);
	}
	printf("releasing lock %lu\n",pthread_self());
	pthread_mutex_unlock(&mutex);
}
void *thread_func(void *args)
{
	fun(2);
}
int main()
{
	pthread_t tid1,tid2,tid3;
	pthread_mutexattr_t attr;	//2nd attribute similar to pthread_create()

	pthread_mutexattr_init(&attr); 	//the second attribute has to be initialised.
	pthread_mutexattr_setkind_np(&attr, PTHREAD_MUTEX_RECURSIVE);// seting  //comment and see the OP.
	pthread_mutex_init(&mutex, &attr); //the main mutex 
/*
in detach thread1.c
  pthread_attr_t attr;  //2nd attribute in pthread_create()
          pthread_t thread;       //a thread is created to stored the Thread_id.
          pthread_attr_init (&attr);      //Initializing all the attribute to some value(say 0)
          pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);    //CREATING A DETACHABLE THREAD. SETING
  

*/
/*
Instead of line 25 26 27 28 29 we can use the MACRO
 pthread_mutex_t recmutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
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

