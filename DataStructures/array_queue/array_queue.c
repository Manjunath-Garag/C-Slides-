#include<stdio.h>
//we can not enter the data until the array elements are pushed and completed poped, only then we can enter the elements in Circular manner
int enqueue(int *queue,int max, int *rear,int *front,int data)
{
	if( *rear == *front) // == max-1)	//Circluar Queue.
	{
		*rear = 0;
		*front = 0;
		queue[(*rear)++]=data;	//if this is not written the Queue won't be Updated.
	}
	else if(*rear == max)
	{
	printf("Queue is FULL\n");	//return 1;
	}
	else
		queue[(*rear)++]=data;	//adding the element and then incrementing the rear.
}	//adding the element and then incrementing the rear.

int dequeue(int *queue, int max,int *rear, int *front)
{
	if (*rear == *front)
	{
		printf("Its Empty from Function\n");	
		return 1;
	}
	else
		return queue[(*front)++];	//After Removing we will Increment the rear.
}

void print(int *queue,int rear, int front) //pass by value.
{
	int i;
	if( (front==rear))
		printf("Queue is Empty\n");
	for(i=front;i<rear;i++) //ex front=0 rear=max
		printf("%d\t",queue[i]);
	printf("\n");
}
