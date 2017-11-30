#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *num_ptr;
	num_ptr = malloc(4*sizeof(int));
	*num_ptr = 111;
printf("%d\n",*num_ptr);
	free(num_ptr);
	*num_ptr = 100;
printf("%d\n",*num_ptr);
	return 0;
}
