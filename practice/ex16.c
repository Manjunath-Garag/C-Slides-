#include <stdio.h>
//auto int x;
//register int x;
static int x=10;
int x ;
int foo()
{
	printf("x %d\n", x);
	return ++x;
}
int main()
{
	foo();
	printf("x %d\n", x);
	return 0;
}
