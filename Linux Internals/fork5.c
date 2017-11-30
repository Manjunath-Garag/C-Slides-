#include<stdio.h>
#include<unistd.h>

//ORPHAN to check the CHILD after parent dies.

/*clt +c
clt + z 
doesnt work cos the pArent is killed and the connection to bash(PARENT of this PROCESS) is gone.
If connection to bash is gone it doesnt take the command line IP.
hence we need to kill the proces  with the hrlp of kill command

kill -9 4233 
kill -9 PID
*/
int main()
{
	int val, i,x,y;
	val = fork();
	if(val == 0)
	{
		while(1)
		{
			x =getpid();
			y=getppid();	//ppid changes one the Parent is dead	INIT becomes the Parent. (After the parent Dies)

			printf("Inside child\n");
			printf("PID:%d\tPPID:%d\n",x,y);
			sleep(2);
		}
	}
	else
	{
		x =getpid();
		y=getppid();

		printf("Inside Parent\n");
		printf("PID:%d\tPPID:%d\n",x,y);
		sleep(5);
	}
}


