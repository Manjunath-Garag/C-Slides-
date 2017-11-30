#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	char *arr[4];

	arr[0]="ls";
	arr[1]="-l";
	arr[2]="-a";
	arr[3]=NULL;

	execv("/bin/ls",arr);
//	execv("/bin/ls","ls",NULL);	//It should be an Array
}

//execv("PATH", base address of the array);

