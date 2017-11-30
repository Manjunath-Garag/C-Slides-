#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
printf("Before exec\n");
execl("/home/emertxe/ecep/basicC/simply", "simply", NULL);
printf("After exec\n");
}

/*
1st argument.
execl("/home/emertxe/ecep/basicC/simply", "simply", NULL);
/home/emertxe/ecep/basicC/simply ::here we are specfing that we need "simply" process.
/simply itself is a Process which is in basiC folder, we are tryin to access simply(Process)

2nd argument.
"simply"
is an exe file can be passed with any no of arguments.   refer execlc

execl("/home/emertxe/ecep/linuxIntervals/assignments/chapter2/a.out",  "a.out","-p","source.txt","dest.txt",  NULL);

3rd Argument (last) is NULL specfies theend of execl command.

*/
