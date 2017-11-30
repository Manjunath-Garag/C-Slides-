#include<stdio.h>
#include<stdlib.h>
#include<array_stack.h>
int main()
{

	int top=-1;
	int n,data,max,ret;
	printf("Enter the array size\n");
	scanf("%d",&max);

	int stack[max];
	while(1)
	{
		printf("Enter your choice\n1:Push\n2:Pop\n3:Peep\n4:Peek\n5:Exit\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1: printf("Enter the Data you want to PUSH\n");
				scanf("%d",&data);
				push(data,max,&top,stack);	//TOP pass by Refrence.
				break;			

			case 2:ret=pop(&top,stack);		//TOP pass by reference.
			       if(ret == 0)
				       printf("The stack in main is empty\n");
			       else
				       printf("The deleted value was LIFO: %d\n",ret);
			       break;	

			case 3:peep(top,stack);			//TOP is Pass by Value.
			       break;

			case 4:peek(top,stack);			//TOP is Pass by Value.
			       break;

			case 5:exit(1);
		}

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
