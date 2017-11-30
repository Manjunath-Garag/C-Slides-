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
	int shmid, len, count = 0;
	char *ptr;
	key_t key;
	char buff[SMSIZE];

	key = 'A'; //key can be hardcoded
	shmid = shmget(key, SMSIZE, IPC_CREAT | 0666);
	if(shmid < 0)
	{
		perror("shmget");
		return 0;
	}
	else
	{
		ptr = shmat(shmid, NULL, 0); //attach the memory segment to ptr
printf("ptr is : %d\n",ptr);
		strcpy(buff, ptr);
		len = strlen(buff) - 1;
		while(len != -1)
		{
			*(ptr + count) = buff[len];	//writing it to the shared Mem.
			len--;
			count++;
		}
		printf("%s\n", ptr);
	}
}
