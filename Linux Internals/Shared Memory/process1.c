#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

#define SMSIZE 100

int main()
{
	int shmid;
	char *ptr, buff[SMSIZE];
	key_t key;
	int pfd[2];
	int pid;
	pipe(pfd);

	key = 'A'; //key can be hardcoded
	shmid = shmget(key, SMSIZE, IPC_CREAT | 0666);//creating a shared memory.
	if(shmid < 0)
	{
		perror("shmget");
		return 0;
	}
	ptr = shmat(shmid, NULL, 0);//attaching a Process.	//which Porcess are we attaching here
printf("ptr is :%d\n",ptr);
	pid = fork();//then creating a parent child Relationship.
	if(pid == 0)
	{
		close(pfd[1]);
		sleep(3);
/* Reading the data from  PIPE(read side) to buffer.*/
		read(pfd[0], buff, strlen(buff) + 1);//FD to BUFF
		int len = strlen(buff), count = 0;
		while(count != len)
		{
			*(ptr + count) = toupper(buff[count]);	//we are writing it to the Shared Mem
			count++;
		}
		printf("Inside Child : %s\n", ptr);

		shmdt(ptr);//Detaching the Process.
	}
	else
	{
		close(pfd[0]);
		__fpurge(stdin);
		printf("Inside parent : ");//we write the data to Shared Memory.(ptr :: the address of the SM)
		scanf("%[^\n]", ptr); //write the content, with help of ptr we access the data in the SM to PIPE.
		//printf("%s\n", ptr);
		strcpy(buff, ptr);//copying data from SM(with the address) to buff on the pipe.
/* Writing the data from BUFFER to PIPE(write side.)*/
		write(pfd[1], buff, strlen(buff) + 1);//fd, buff, size. BUFF to FD.	

		wait();//SM is not Naturally Sync.
		sleep(10);
		printf("%s\n",ptr);

		shmdt(ptr);//detaching the Porcess.
	}
}
