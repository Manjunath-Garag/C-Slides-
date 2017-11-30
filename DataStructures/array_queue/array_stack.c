#include<stdio.h>

void push(int data, int max, int *top, int *stack) //top is Pass by REfrence.
{
	if(*top == max-1)	//top will be passed as -1.
	{
		printf("The Stack is full\n");
	}
	else
	{
		stack[++(*top)]=data;	//1st Increment the TOP then add the Data.
	}

}

int pop(int *top, int *stack)	//top is Pass by Refrence. The change in the Top will be reflected in the main function.
{
	if (*top == -1)
	{
//		printf("Stack is Empty\n");
		return 0;
	}
	else
	{
			return stack[(*top)--];	//element is Deleted then TOP is Decremented.
	}
}

void peep(int top, int *stack ) //top is pass by Value. beacuse we should not change the value of top  by passing by PASS-BY-REF
{	//just to print the elements in the list. from 0 to top.
	int i;
	if (top == -1)
	{
		printf("PEEP:: Stack is Empty\n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d\t",stack[i]);
		}
	}printf("\n");
}

void peek(int top, int *stack)	//top is Pass by Value, because we are not supposed to change the value of top.
{	//the topmost element.
	if(top == -1)
	{
		printf("PEEK:: Stack is Empty,Can not find the topmost ele\n");
	}
	else
	{
		printf("\nThe top most element is %d\n",stack[top]);
	}
}
