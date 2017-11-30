#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

/* Define the shared memory size*/
#define SMSIZE 100

int main()
{
	int n=0;
	int shmid;	//to store the id like USN
	int *shm;	//pointer to store theaddress.
	key_t key;
	/* Key can be hard-coded but use the same key in reader and writer.*/
	key = 'B';

	/*Create a shared memory.*/
	shmid = shmget(key,SMSIZE, IPC_CREAT | 0666);
	printf("The id returned by shmget is %d\n",shmid);

	if(shmid < 0)
	{
		perror("shmget");
		exit(1);
	}
	else
	{
		shm=shmat(shmid, NULL, 0);	//Shared Mem is attached to Respective Calling Process
		//getchar();
		/*
		   TODO::
		   1.execute ipcs command and check if the shared mem is created.
		   2.take the value from the user which you want to write.
		   3.perform shared mem detch by raeding the man page.
		 */
		printf("The value which was entered was from writer %d\n",*shm);
		/* this is the reason why shared Memory is Fastest IPC 
		   since we can dirctly scan the values unlike  PIPEs and FIFO we do not use read write system calls int SHARED MEMEORY */
	}//else
	printf("Do you want detach\nenter 1 to detach\n");
	scanf("%d",&n);
	printf("%d\n",n);
	while(n == 1)
	{
		int n = shmdt(shm);//Detaching the Process from the address of the Shared Memory
		printf("%d \n", n);
	}
}

