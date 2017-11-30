#include<stdio.h>
#include<pthread.h>

struct char_print_parms
{
	char character;
	int count;
};

void * print_xs(void * arg)	//Argument is Void *   and 	return type is also void *
{
	struct char_print_parms* p = (struct char_print_parms *) arg;		//void * has to be type-casted to structure Pointer.
	int i;
	for(i=0; i < p->count; i++)
		fputc(p->character,stderr);
	return NULL;
}

int main()
{
	pthread_t thread1_id;	//creating a Variable to store the id of the thread.
	pthread_t thread2_id;

	struct char_print_parms thread1_args;	//struct var
	struct char_print_parms thread2_args;	//structure Cos we want to pass More than 1 Variable.

	thread1_args.character = 'x';
	thread1_args.count = 15;
	pthread_create(&thread1_id, NULL, &print_xs, &thread1_args);

	thread2_args.character = 'o';
	thread2_args.count = 20;
	pthread_create(&thread2_id, NULL, &print_xs, &thread2_args);

	pthread_join(thread1_id, NULL); //wait until thread1_id finishes. or terminate. and accepts the return value.

	pthread_join(thread2_id, NULL); //waits until thread2_id finishes

	return 0;
}

/*
//use pthread_join (Similar to wait() in Process)

pthread_join	similar to wait()  
1.wait for the thread to finish
2.clears the stack memory
3.to collect the return value from thread.
 */
