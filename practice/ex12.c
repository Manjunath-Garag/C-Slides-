#include <stdio.h>
#include <unistd.h>
int main()
{
	while (1)
	{
		//printf("Hello\r");
		printf("\rHello");
fflush(stdout);
		sleep(1);
	}
	return 0;
}
