#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;//typedef unsigned interger
	char *message;
	int n;
	int exit_code;

	printf("fork program starting\n");
	pid = fork();

	switch(pid)
	{
		case -1:	exit(1);

		case 0:message = "This is child Process\n";
		       n=15;
		       exit_code=37;
		       printf("Child pid = %d\n",getpid());
		       break;

		default : 
		       message = "This is Parent Process\n";
		       n=3;
		       exit_code=0;
		       break;

	}//switch

	for(; n >0 ; n--)
	{
		puts(message);
		sleep(1);
	}

	if(pid)	//this will run only for Parent.
	{
		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);

		printf("Child has finished: PID = %d\n",child_pid);
		if(WIFEXITED(stat_val))
			printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
		else
			printf("Child terminated Abnormally %d\n",WEXITSTATUS(stat_val));	//use kill pid

	}
	exit(exit_code);



}//main

