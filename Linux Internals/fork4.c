#include<stdio.h>
#include<unistd.h>

//To check if the Process is ALIVE
// do not enter the value , check if the process is alive with pstree command
//ORPHAN procees is adopted by init.

int main()
{
	//	printf("Enter a number in child process\n");	//to check if Process is alive.
		__fpurge(stdin);
	int val, i,x,y,n,m;
	val = fork();
	if(val == 0)
	{
		x =getpid();
		y=getppid();
		n = 3;

		printf("Inside child\n");
		printf("PID:%d\tPPID:%d\n",x,y);
		printf("Enter a number in child process\n");	//to check if Process is alive.
		__fpurge(stdin);
		scanf("%d",&n);	
		//read(0, &n, 4);
//sleep(4);
		printf("n--%d\n", n);
	//do not enter  in cmd line then go to another terminal and use pstree cmd. YOU can see the Process alive somewhere int the tree
	}
	else
	{
		x =getpid();
		y=getppid();
	//	printf("Inside Parent\n");
	//	printf("PID:%d\tPPID:%d\n",x,y);
		wait(NULL);
		__fpurge(stdin);

		printf("Enter a number in parent process\n");
		__fpurge(stdout);
		scanf("%d",&m);
		printf("m---%d--\n", m);
	}
}

/*
─gnome-terminal─┬─bash─┬─vi
     │         │         │      │                │      └─wc
     │         │         │      │                ├─bash───8*[a.out───a.out]
     │         │         │      │                ├─bash───pstree


LINE 38 a.out is still alive
first a.out is exe then in another terminal pstree was execute hence the corresponding  TREE Structure
BASH Complier is the Parent because that is where we exe the cmd.

Inside Parent
PID:4623	PPID:4327	//i guess bash is parent of this Process Cos that is wer this program was ran.

Inside child	//duplicate
PID:4624	PPID:4623 //this is parents PID

THE ROOT STRUCTURE IS WRITTEN BELOW


init		1st Process exe by the OS.

Treminal	UI where we enter	this where bash is executed (RUN).//bash is an APPLICATION.

Bash		an application where we run the code or where we write the cmds to execute.
//BASh is command line Interpreter  takes the command line arg. i.e ./a.out AND is a PARENT to Process p1.
a.out		parent	P1

a.out		child	P2



init		pcb1
TERNIMAL	pcb2
BASH		pcb3
P1		pcb4
P2		pcb5

All the pcb would be stord in the Linked List Manner.
pcb1 --> pcb2 --> pcb3 --> pcb4 -->pcb5
init	ter	bash	   p1	  p2
p1 stack is destroyed and his corresponding pcb4 is also destroyed,
Now pcb5 (p2) has no parent and will be a ORPHAN and Adopted by init
it has the access only with init since it is adopted. and not with ter and bash Hence we have to Kill the child Process wit kill CMD.

		Theory --> Of how Parent and Child are Executed.
P1(Parent) is done and executed then that stack is destroyed, but P2(child) keeps on executing in the Ternimal and doesnt respond to the Command line Insrtuctions(clt + z , clt + c) this is because 
Since P2 is is the CHILD of P1 and P1 Stack is destroyed P2 will not have a access to other Process (bash, terminal) except init. IT becomes an ORPHAN (Parent is dead before the child) All the Orphan Processes are always Adopted by the init.
It is the responsiblity of the parent to clear the memory of the child.Hence this work is done by INIT by adopting the ORPHAN(child)process

			Why is ORPHAN PROCESS Adopted by INIT??
Orphan Process is adopted by INIT because , once the child finishes Exectuion , the Resources has to be freed (Usually done by Parent) Since Parent is dead that responsibliy has to be taken by the INIT Process ( Init Process will clean the Orphan Processes Resources) 

The link is lost for P2 with the other Processes.	(Except INIT) It is an ORPHAN and Adopted by INIT.
So we need to kill the child Process to stop it from running using :: kill -9 pid
 */
