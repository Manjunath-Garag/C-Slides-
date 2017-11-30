#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fds[2];	//THESE ARE NOTHING BUT FILE-DESCRIPTORS.
	pid_t pid; //unsigned int.
	int num, num1;

	/* Create a pipe here, its Important to do before fork. */
	/* A Virtual (MEMORY)file is created on the Kernel side when a pipe() system call is made.
	   It is a One-Directional way of communcation.

	 */
	pipe(fds);
	/* When a fork() call is made A duplicate copy is created. 
	   Now there are 2 fds[2] i.e 4 Interger arrays 
	   So while using The child for writing the data in the Pipe we close the READ PIPE of the child Process ans vice versa
	   While READING (Extracting data ) from the file, we close the WRITE  */
	pid = fork();

	/*
	   We need to run 2 Processes that is why we need to fork so that we can run 2 Process one after the Other.
	 */

	/* PIPE is AUTOMATIC SYNCHRONIZATION
	   i.e :: Here the Parent Process runs first.
	   The Parent process is Reading , there is NOthing to read until The child has written something to the PIPE.
	   the parent will wait untill the Child writes somthing into the PIPE Later reads the Respective data from the PIPE.
	 */
	if(pid == 0)
	{
		printf("Inside child Process...\n");
		printf("Enter the INteger \n");
		scanf("%d",&num);	//while writing, reading is closed.
		scanf("%d",&num1);	//while writing, reading is closed.
		close(fds[0]);
		/* Write Info into the Pipe for the Parent to read */
		write(fds[1],&num,sizeof(num));	//WHERE  WHAT SIZE
		write(fds[1],&num,sizeof(num));	//WHERE  WHAT SIZE

	}
	else
	{
		close(fds[1]);	//While Reading, Writing is closed.
		printf("Inside Parent Process...\n");
		/* Read from the pipe and Print the Output*/
		read(fds[0],&num,sizeof(num));
		read(fds[0],&num,sizeof(num1));
		printf("num %d\n",num);
		printf("num1 %d\n",num1);	//Pipe reads only once.
		printf("The value received from Parent\n");
	}
}
/*
   Automatic Sync
   i.e the Parent runs first there is nothing to read, it will wait untill the Chils Writes Somrthing the Reads the data from the CHild.
 */
