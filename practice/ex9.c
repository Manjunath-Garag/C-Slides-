#include<stdio.h>

int main()
{
	int a,b,c,d;

	/* printf("here: %d\n",printf("%d %d %d %d",a,b,c,d));
	   printf("here: %d\n",printf("Hello"));
	   printf("%o\n",8);
	   printf("%o\n",15);
	   printf("%o\n",24);
	   printf("%o\n",31);
	   printf("%x\n",16);
	   printf("%x\n",48); */
	unsigned int mask=1; 
	printf("Enetr octal\n");
	scanf("%d",&a);
	mask = mask<< 31;
	while(mask)
	{
		(a & mask) ? printf("1") : printf("0");
		mask >>= 1 ;
	}
}

