#include<stdio.h>
#include<stdlib.h>
#include<array_queue.h>

int main()
{

	int rear=0,front=0,max;
	int n,edata;
	printf("Enter the array size\n");
	scanf("%d",&max);
	int queue[max];
while(1)
{
	printf("Enter your choice\n1:Enqueue\n2:Dequeue\n3:Print list\n4:Exit\n");
	scanf("%d",&n);

	switch(n)
	{
		case 1: printf("Enter the Data you want to Enqueue\n");
			scanf("%d",&edata);
			enqueue(queue,max,&rear,&front,edata);
			break;			

		case 2: dequeue(queue,max,&rear,&front);
			break;	
		
		case 3: print(queue,rear,front);
			break;

		case 4: exit(1);
	}
 print(queue,rear,front);

}

}
	/*
	   enqueue(queue,max,&rear,10);
	   enqueue(queue,max,&rear,15);
	   enqueue(queue,max,&rear,17);
	   print(queue,rear,front);

	   dequeue(queue,max,&rear,&front);
	   print(queue,rear,front); 	//pass by value.

	   enqueue(queue,max,&rear,19);
	   enqueue(queue,max,&rear,22);
	   print(queue,rear,front); 	//pass by value.

	   dequeue(queue,max,&rear,&front);
	   print(queue,rear,front); 	//pass by value.

	   enqueue(queue,max,&rear,23);
	   enqueue(queue,max,&rear,25);
	   print(queue,rear,front); 	//pass by value.
	   }


	 */
