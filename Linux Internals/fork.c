#include<stdio.h>
#include<unistd.h>

//in this code both printf statments are executed.
//both are printed in different positions.

int main()
{
	int val;
	val = fork();		//returns the pid of the child Process.
	if(val == 0)		
	{	
		//printf("INSIDE CHILD : %d\n",getppid());
		//printf("PID : %d\n",getpid());
		printf("Hello");	//child
	}
	else
	{
		printf("World\n");	//parent .Parent is executed first.
		//printf(" INSIDE PARENT , PPID : %d\n",getppid());
		//printf("PID : %d\n",getpid());
		//printf("Fork returns the pid of the child %d\n",val);
	}

}
/*
   Process1 			process2
   World				Child.

   When Program starts execution :: i.e Procees1
   Fork call is made , similtaneosly a Duplicate Process [ Along with the memory ] is created due to Fork call(i.e Procees 2)
   then the Execution of Process 1 is continued the else part of the If-condtion is executed.i.e  because The fork returns a  Possitive  value when a the call is made, hence else part is executed.

   the Process 2 Starts execution from the very next line of the Fork call ( i.e the if condtion ) 
   the Condtion turns out to be true for the Process 2 Cos The fork call is never made (the execution itself starts off from line 9 if-cond)


Output:
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ ./a.out 

World	//Parent procees is Executed 

emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ Hello	//child
then the bash is executed ( RAM Does it)
then Child Process isExecuted.

IMPORTANT ::

Process of Exe :: 
Parent
Bash
Child


For the above Program the structure of the Tree Parent-Child goes as follows.

Init

terminal

bash

Parent Process		//Process1

Child Process		//process2
 */
