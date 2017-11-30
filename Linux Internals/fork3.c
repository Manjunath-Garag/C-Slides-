#include<stdio.h>
#include<unistd.h>

//in this code both printf statments are executed.
//both are printed in different positions.
int main()
{
	int val, i,x,y;
	val = fork();	//fork call will return the PID of the Child Process.
		printf("After fork val in parent : %d\n",val);	
	if(val == 0)
	{
		x =getpid();
		y=getppid();

		printf("\nInside child\n");
		printf("PID:%d\tPPID:%d\n",x,y);
		printf("val is : %d\n",val);	//for child it returns the 0  
		sleep(2);
	}
	else	//on error it returns -1
	{
		x =getpid();
		y=getppid();

		printf("\nControl comes to Parent First.  Inside Parent\n");
		printf("PID:%d\tPPID:%d\n",x,y);
		printf("val in parent : %d\n",val);	//for parent it returns the pid of the child.
		sleep(2);
	}
}

/*

Inside Parent
PID:4623	PPID:4327

Inside child	//duplicate
PID:4624	PPID:4623 //this is parents PID

*/
