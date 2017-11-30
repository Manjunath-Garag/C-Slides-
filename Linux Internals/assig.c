#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		printf("Child \n");
		//execvp("fork",argv);
		execvp(argv[1],argv); //executavle file has to given here.
	}
	else
	{
		int wait;
		int ret;
		printf("Parent\n");
		ret=waitpid(pid,&wait,0);	//wait will return "0" if it fails.
		if(WIFEXITED(wait))
		{
			printf("The child exites Normally\n");
		}
		else
		{
			printf("The child Exited Ab-normally\n");
		}
	}
}

