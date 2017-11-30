#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<pthread.h>

void *allocate_buffer(size_t size)
{
	printf("Resource Allocated\n");
	return malloc(size);
}

void deallocate_buffer(void *buffer)
{
	free(buffer);
	printf("\n Resouce Freed\n");
}

void *do_some_work(void *p)
{
	void *temp_buffer = allocate_buffer(1024);
	pthread_cleanup_push(deallocate_buffer, temp_buffer);	//function pointer , arguments for the function pointer.
	printf("cleanup handler pushed\n");

	int i;
	for(i=0; i<10000; i++)
		fputc('c',stderr);//since we are canceling the thread it prints very less times. comment and check the cancel_function.
	pthread_cleanup_pop(1); //0,1	//clears the memory.
}

int main()
{
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, &do_some_work, NULL);
	usleep(100);
	pthread_cancel(thread_id);	//comment and see.
	pthread_join(thread_id, NULL);
	return 0;
}

