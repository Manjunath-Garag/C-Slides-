#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;	//it is just a Counter.
void *thrd_func(void *args)	//consumer.
{
	while(1)
	{
		sem_wait(&sem);	// if sem value is "0" it will block. 0 means NO resource
		/* Do something*/
		printf("Taken semaphore by and waiting for the Product to be ready :%lu\n",pthread_self());
	}
}

void *producer_func(void *args)
{
	while(1)
	{
		sleep(3);
		printf("Producer Produced, ");
		printf("Semaphore adding by %lu \n\n", pthread_self());
		sem_post(&sem);//after the work is done, When Product  is ready we release the lock (UNLOCK).
	}
}
int main()
{
	pthread_t tid0, tid1,tid2;

	sem_init(&sem,0, 1 );//3rd para is the number of Connections
/*2nd para : tells that this function used for Thread 
if 2nd para was 1 : then it would be for Process.
the 3rd Para :: tells The number of users.
*/
	pthread_create(&tid0, NULL, thrd_func, NULL);		//consumer.	
	pthread_create(&tid1, NULL, thrd_func, NULL);		//consumer.
	pthread_create(&tid2, NULL, producer_func, NULL);	//Producer.

	pthread_join(tid0, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	//pthread_join(tid0, NULL);
	return 0;
}

/*
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/synch$ ./a.out 
Taken semaphore by :3067382592
Semaphore adding by 3058989888 

Taken semaphore by :3067382592
Semaphore adding by 3058989888 

Taken semaphore by :3075775296
Semaphore adding by 3058989888 

Taken semaphore by :3067382592
Semaphore adding by 3058989888 

Taken semaphore by :3075775296
Semaphore adding by 3058989888 

Taken semaphore by :3067382592
Semaphore adding by 3058989888 

*/
