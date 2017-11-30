#include<stdio.h>
#include<pthread.h>

int x = 0;	//a normal Global Variable, NOt a Mutex Variable

/*
Hence there might be a chance that Thread-swirching might happen inbetween and the OP might be 5 or 25 sometimes.
*/
void *thread_func (void * arg)
{
	while(1)
	{
		x=5;
		x+=10;
		printf("x is %d\n",x);
//		printf("thread is %lu\n",pthread_self());
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


/*
./a.out | grep -v 15
prints the out other than 15
op might be 5, 25 
depend on the cores in the CPU.
for virtual box 1 core would be assigned hence it diff to see the op.
*/
