#include<stdio.h>
#include<unistd.h>

int main()
{
	fork();
	fork();
	fork();
	sleep(2);
	printf("Hello\n");
	//printing sequence is Dependent on the Ram and the Scheduling Process. Depends on which process is Scheduled.
//Concurrently the Process is executed unlike SEQUENTIAL.
}

/*
CONCURRENT PROGRAMMING. : execution points are different. the next line
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ gcc fork9.c 
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ ./a.out 
Hello
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ Hello //BASH is killed here then the child process is exe
Hello
Hello
Hello
Hello
Hello
Hello
Parent is executed first, then Parent Dies,BAsh is killed line 20 then the Child Processes is executed
*/
		//we can not predict the Synchoronization.
/*
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ ./a.out 
Hello
Hello
Hello
emertxe@emertxe-VirtualBox:~/ecep/linuxIntervals/assignments/chapter1/man_cmds$ Hello
Hello
Hello
Hello
Hello
*/
