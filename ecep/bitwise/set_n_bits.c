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
	
	mask=(1<<n)-1;//No of bits to be extracted.
	
	mask=mask<<p;// No of position.
	
	maskk=~mask;// Negation. For Clearing the Bits.
	
	res1=(maskk & value); //res1 for anding negation and value

	res2=(mask & num); // res2 for anding mask and the num value.

	
	result=res1 + res2; // finally replacing the no of bits (extracted) from res2 and added with res1.
		
	return result;
}
