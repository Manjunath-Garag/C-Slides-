#include <stdio.h>
int main()
{
	int num = 100;
	const int *iptr = &num;
	printf("Number is %d\n", num);
//	num = 200;
*iptr = 200;
	printf("Number is %d\n", *iptr);
	return 0;
}
