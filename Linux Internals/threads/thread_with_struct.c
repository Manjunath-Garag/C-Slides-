#include<stdio.h>
#include<pthread.h>

//NO OUTPUT.

struct char_print_parms
{
	char character;
	int count;
};

void * print_xs(void * arg)
{
	struct char_print_parms* p = (struct char_print_parms *) arg;
	int i;
	for(i=0; i < p->count; i++)
		fputc(p->character,stderr);
	return NULL;
}

int main()
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	struct char_print_parms thread1_args;	//struct var
	struct char_print_parms thread2_args;

	thread1_args.character = 'x';
	thread1_args.count = 300000;
	pthread_create(&thread1_id, NULL, &print_xs, &thread1_args);

	thread2_args.character = 'o';
	thread2_args.count = 200000;
	pthread_create(&thread2_id, NULL, &print_xs, &thread2_args);
	
	return 0;
}
/*
//the main thread is not waiting fro other threads to finish 
//hence no OP
//use pthread_join (Similar to wait() in Process)

pthread_join	similar to wait()  
1.wait for the thread to finish
2.clears the stack memory
3.to collect the return value from thread.
*/
