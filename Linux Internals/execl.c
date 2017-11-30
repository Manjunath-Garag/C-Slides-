#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
printf("Before exec\n");
//execl("/bin/ls","ls",NULL);
//execl("/bin/ls","ls","-al",NULL);
//execl("/home/emertxe/ecep/linuxIntervals/assignments/chapter2/a.out",  "a.out", NULL);
execl("/home/emertxe/ecep/linuxIntervals/assignments/chapter2/a.out",  "a.out","-p","source.txt","dest.txt", NULL);
printf("After exec\n");	//this line is not executed.
}

// execl("PATH", "command we want to execute", NUll/*to specfiy the end.*/);

/*
" ls " is a process we are passing the address of the process (ls)

emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ gcc execl.c 
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ ./a.out 

Before exec	//printf statment in main (i.e process 1)

//then it is replaced with Process 2(i.e execl)
//execl will replace the process 1 with execl process( ls ) hence printf("After execl"); is not printed.

a.out	  execl.c  fork3.c  fork5.c  fork7.c  fork9.c  fork_kill.c  time.c   wait2.c
cmds.txt  fork2.c  fork4.c  fork6.c  fork8.c  fork.c   open.c	    wait1.c

emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ 

//
exec is variadic function (can pass any no of Arguments and should end with a NULL)

execl("/home/emertxe/ecep/linuxIntervals/assignments/chapter2/a.out",  "a.out", NULL);


*/
