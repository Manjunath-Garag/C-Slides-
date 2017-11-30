#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int x=10;
int main()
{
	int i=10;
	int pid =vfork();
	if(pid==0)
	{
		x++;
		printf("Child here\n\n");
		printf("child i:%d\t x:%d\n",i,x);
		i = 22;
		exit(0);	//Proper termination should happen.	if not done CORE Might get dumped.
		//	execl("/bin/ls","ls",NULL);
	}
	else
	{
		//	execl("/bin/ls","ls","-al",NULL);
		printf("Parent\n");
		x++;i++;
		printf("i:%d\t x:%d\n",i,x);
	}
}

/*
ON vfork whatever you do, A duplicate Process is Never Created.
vfork() is called.

### ::: Both Parent and child Process will be pointing to the same Memory Location.

Always the Child would execute first , Untill then the Parent waits for the Child to Finish the Execution, and After the child executes.
the Parent will start its Execution.

In the Above Example,All the SEGMENTS 
		Parent 		Child
CODE 
STACK		
HEAP
DATA 

the value of i=10
The child always executes first the value of i was perviously 10 now it is Change to 22 by child.
which would also reflect on the Parent Process.
Hence the i in the parent side also will be 22(OVER-RIDEN) by the child.
ON the stack segment when the data will be Over-riden each time. the latest value will be updated.
*/
