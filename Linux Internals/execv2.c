#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
printf("The OP for the process is  \" %s \" is\n",argv[1]);

execv("/bin/ls",argv+1);     // ./a.out is given in the cmd line so start from the next address. ./a.out ls(we are considering only "ls")
}
