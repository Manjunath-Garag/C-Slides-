
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

	void to_upper(str,)
int main()
{
	int fds[2];
	pid_t pid; //unsigned int.
	unsigned char str[1024];
	int shmid;      //to store the id like USN
	int *shm;       //pointer to store theaddress.
	key_t key;
	/* Key can be hard-coded but use the same key in reader and writer.*/
	key = 'B';

	/*Create a shared memory.*/
	shmid = shmget(key,SMSIZE, IPC_CREAT | 0666);
	printf("The id returned by shmget is %d\n",shmid);

	/* Create a pipe here, its Important to do before fork. */

	pipe(fds);//Indirectly open() is used Once pipe is called a Virtual file is Creted on the Kernel.

	pid = fork();
key = 'B';
	if(pid)
	{
		printf("Inside Parent Process...\n");
		printf("Enter the string \n");
		scanf("%s",str);
		printf("%d\n",strlen(str));//strlen excludes NUll 
		close(fds[0]);
		/* Write Info into the Pipe for the Parent to read */
		write(fds[1],str,strlen(str));	//the size should be the same for Both read and write Sysytem calls.

	}
	else
	{
		close(fds[1]);
		printf("Inside Child Process...\n");
		/* Read from the pipe and Print the Output*/
		read(fds[0],str,strlen(str));
		str=touuper(str);
		printf("%s\n",str);
		printf("The value received from Parent\n");
		//printf("%s\n",str);
	}
	return 0;
}
/*
   Automatic Sync
   i.e the Parent runs first there is nothing to read, it will wait untill the Chils Writes Somrthing the Reads the data from the CHild.
 */

