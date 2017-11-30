#include<stdio.h>
#include<pthread.h>
//Collecting Return Value from the Thread.

struct parms
{
	int a;
	int b;
};

void *add (void *a)
{
	struct parms *d = (struct parms*)a;
	int c;
	c = (d->a + d->b);
	return ((void *)c);//return address of c, after TYpe-casting

}

int main()
{
	pthread_t thread_id;
	struct parms p;
	int res;
	printf("Enter the values\n");
	scanf("%d%d",&p.a, &p.b);
	pthread_create(&thread_id, NULL, &add, &p);
	pthread_join(thread_id, (void **)&res);		//if join is'nt used then , it doesnt wait and O/p will be Garbage
	printf("\nThe Value after Execution is %d\n",res);
}

/*
It has to accepted as Void Pointer, Hence (void *) 
Consider the address of res as 200 The equation Would be
(void **)&res = (void *) 100
(void **)200 = (void *)100	//one *is for pointer another is for type-casting
like int *ptr = &x;

c = 10
address of c is 100
we are sending 100 to the Function.

it has to be de-refrenced Twice. to get the result
*/

