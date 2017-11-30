#include<stdio.h>
#include<unistd.h>

int main()
{
	int val;
	val=fork();
	if(val == 0)
	{
		while(1)	//parent dies and child goes to infinite loop ORPHAN and adopted by init.
		{
			int x= getpid();
			int y= getppid();
			printf("%d %d\n",x,y);

				printf("Inside child\n");
			sleep(2);
		}
	}
	else
	{
		printf("Inside parent\n");
	}
}

/*
Parent will die and child becomes an Orphan
and the child Process is adopted by INIT and hence clt+z ang clt+c does'nt work  :: this is because The parent Process is dead and for the
child the parent and the corresponding processess above the parent (bash terminal) is'nt accessable hence it has to killed by the using
kill command

*/
