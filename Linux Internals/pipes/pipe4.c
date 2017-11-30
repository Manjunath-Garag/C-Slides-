#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

//./a.out ls wc
int main(int argc, char *argv[])
{
	int fds[2];
	pid_t pid, pid2; //unsigned int.
	//fds[0] --> read;
	//fds[1] --> write;
	/* Create a pipe here, its Important to do before fork. */

	pipe(fds);//Indirectly open() is used Once pipe is called a Virtual file is Creted on the Kernel.
	pid = fork();

	if(pid == 0)
	{
		printf("Inside child Process...\n");
		close(fds[0]);
		dup2(fds[1],1); //new , old  printing it on the ARRAY fds[1] rather than on the SCREEN "1".
		execl("/bin/ls","ls",NULL);
//		execvp(argv[1], argv+1);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0],0);//stdin's new functionality is fds[0](reading from the pipe)
		execl("/usr/bin/wc","wc",NULL);
		printf("Parent 2\n");
	}
	return 0;
}
/*
   Automatic Sync
   i.e the Parent runs first there is nothing to read, it will wait untill the Child Writes Somrthing the Reads the data from the CHild.
 */
