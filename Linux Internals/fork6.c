#include<stdio.h>
#include<unistd.h>
//Zombie State

int main()
{
	int val, i,x,y;
	val = fork();
	if(val == 0)
	{
		x =getpid();
		y=getppid();

		printf("Inside child\n");
		printf("PID:%d\tPPID:%d\n",x,y);
		sleep(4);//child Process dies after 4 secs i.e Before Parent.
		printf("Child dying\n");
		//Zombie State is for 4 sec(After child dies, parent dies after 4 sec) that is the time gap bet 4 to 8 i.e 4 sec after these parent dies 
		//after parent dies it cleans up the Child Process it has created. 
	}
	else
	{
		x =getpid();
		y=getppid();

		printf("Inside Parent\n");
		printf("PID:%d\tPPID:%d\n",x,y);
		sleep(10);
		printf("Parent died\n");
	}
}

/*
   Child is dying the the process (of child ) has to be cleaned up by the Parent.
   Parent will clean the child process only when it(PARENT) dies.

   the CHILD waiting Parent to clean the Process is called Zombie state.   ***IMPORANT***

   line containing <defunct> is the Zombie State.
   defunct means Process is dead but not Cleaned-Up (which is Zombie state) 

   use ps -aef | grep PID of child
   emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ ps -aef | grep 3188
   emertxe   3188  3117  0 14:39 pts/14   00:00:00 ./a.out
   emertxe   3189  3188  0 14:39 pts/14   00:00:00 [a.out] <defunct>    //Zombie process: waiting for Parent to clean the Dead Child-process
   emertxe   3191  3173  0 14:40 pts/25   00:00:00 grep --color=auto 3188

   emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ ps -aef | grep 3188
   emertxe   3195  3173  0 14:40 pts/25   00:00:00 grep --color=auto 3188 //this after the Parent is dead.
 */
