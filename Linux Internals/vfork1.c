#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int i=10;
	int pid =vfork();

	if(pid==0)
	{
		i++;	//11
		printf("Child here\n\n");
		printf("%d\n",i);sleep(3);
		execl("/bin/ls","ls",NULL);	//if you comment this CORE GETS DUMPED.  Cos in vfork child process should Exit Properly.
	}
	else	//Parent will wait for the child to execute.		AUTOMATIC WAIT
	{
		printf("Parent\n");
		printf("%d\n",i); //11
		i++;
		printf("%d\n",i);	//12
		execl("/bin/ls","ls","-al",NULL);
		printf("%d\n",i);	//12
	}
}

/*
   Vfork should be terminated Properly , OTHERWISE core gets Dumped.
   Parent waits for the child to be execute first , that is property of Vfork.
 */

