#include<stdio.h>
int setnbits(int value,int n,int p,int num);

int main()
{
	int value,num,n,p,result;

	printf("Enter the value\n");
	scanf("%d",&value);

	printf("Enter the no of bits to be extracted\n");
	scanf("%d",&n);

	printf("Enter the position from where it has to be extracted\n");
	scanf("%d",&p);

	printf("Enter the number\n");
	scanf("%d",&num);

	result=setnbits( value,n,p, num);

	printf("The Final result is %d",result);

	return 0;
}


int setnbits(int value,int n,int p,int num)
{
	unsigned char mask,maskk;

	int res1,res2,result;
	mask=(1<<n)-1;
	mask=mask<<p;
	maskk=~mask;
	res1=(maskk & value);

	res2=(mask & num);

	result=res1 + res2;
	return result;
}
