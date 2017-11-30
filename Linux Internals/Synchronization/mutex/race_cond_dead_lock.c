#include<stdio.h>
#include<pthread.h>

int x = 0;
int y = 0;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;	//we are creating a Mutex variable. Which would be INitialized to Initial Values.
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;	//we are creating a Mutex variable. Which would be INitialized to Initial Values.
//In the Macro the var mut will be INitialized to its Default Values. ( 0  Unlock state)

void *thread_func (void * arg)
{
	while(1)
	{
		pthread_mutex_lock(&mut);	//LOCK
		x=5;	//this is also a Critical Section. ONly 1 thread will be allowed to access at time i.e The Thread which is Locked.
		x+=10;
		pthread_mutex_lock(&mut2);	//LOCK
		y=10;y+=1;
		printf("x is %d in thread %lu\n",x,pthread_self());
		printf("y is %d in thread %lu\n",y,pthread_self());

		pthread_mutex_unlock(&mut2);	//UNLOCK
		pthread_mutex_unlock(&mut);	//UNLOCK
	}
}

int main()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_create(&tid1, NULL, &thread_func, NULL);
	pthread_create(&tid2, NULL, &thread_func, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}

// sudo apt-get install  glibc-doc		Install this Package. for man page of race cond

/*
   ./a.out | grep -v 15
   prints the out other than 15
   op might be 5, 25 
   depend on the cores in the CPU.
   for vitual box 1 core would be assigned hence it deiff tothe op.
 */
