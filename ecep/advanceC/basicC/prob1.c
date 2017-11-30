#include<stdio.h>

int main()
{
	int idx,m,sum;
	float ave=0; // ave has to be of float type.
	int array[5]={13,5,-1,8,17};
	sum=0;
	for(idx=0;idx<5;idx++)
	{
		sum=sum+array[idx];
	}
	printf("The sum is %d\n",sum);
	m=sum;
	ave=(float)sum/5; //TYPE CASTING has to USED.
	printf("The ave is %.1f\n",ave);
	return 0;
}
