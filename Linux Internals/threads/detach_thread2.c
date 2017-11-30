
#include<stdio.h>
#include<pthread.h>

/*detaching with function call.
Very simple, we just need to call the function pthread_detach(thread_id);
*/

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
//	return NULL;
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

	int a = pthread_detach(thread1_id);	//On Success 0, err-no On Failure.
	printf("thread1 : %d\n",a);

	int b = pthread_detach(thread2_id);
	printf("thread2 : %d\n",b);
	return 0;
}
