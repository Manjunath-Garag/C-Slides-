#include <stdio.h>
#include<stdlib.h>
int main()
{
	char *ptr;
	int iter;
	ptr = malloc(5* sizeof(char));
	for (iter = 0; iter < 5; iter++)
	{
		ptr[iter] = 'A' + iter;
	}
	free(ptr);
	for (iter = 0; iter < 5; iter++)
	{
printf("%c\n", ptr[iter]);
	}
	return 0;
}
