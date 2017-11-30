#include<stdio.h>
#include<pthread.h>

/*Print x's to stderr, the Parameter is Un-used, Does not return*/

void * print_xs(void * unused)
{
	while(1)
		fputc('x', stderr);
	return NULL;
}

int main()
{
	pthread_t thread_id;
	/*Creat a New Thread, the new thread will run the print_xs function*/
/*
1st parameter is address of the Thread_id tostore the id.
2nd Para to change the behaviour of the thread JOINABLE or DETACHABLE.
3rd Para is the function to which the thread has to be assigned.
4th para is The attributes to that function of the 3rd parameter.
*/

	pthread_create(&thread_id, NULL, print_xs, NULL);
//1st para is passed as an Address cos ,  ID of the thread has to stored in it.
/*
int a = pthread_detach(thread_id);
printf("%d\n",a);
*/
	/*Print o's , x's continously to stderr*/
	while(1)
		fputc('o',stderr);
	return 0;
}

/*
-lpthread is including the library
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/threads$ gcc thread.c -lpthread
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/threads$ ./a.out 
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

It can be xoxoxoxoxoxo
ooooxxxx
xxxxoooo
*/
