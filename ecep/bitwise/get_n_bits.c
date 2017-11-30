#include<stdio.h>

int getnbits(int num,int n,int p);// prototyping
int toggle(int num,int n,int p);


int main()
{
	int num,p,n,result,res_toggle;
	// unsigned char mask;

	printf("Enter the number\n");
	scanf("%d",&num);

	printf("Enter the no of Bits to be extracted i.e mask\n");
	scanf("%d",&n);

	printf("Enter the Position from where it has to be extracted\n");
	scanf("%d",&p);


	result=getnbits(num,n,p);//Function call.
	res_toggle=toggle(num,n,p);//Toggle

	printf("The final Result is %d\n",result);
	printf("The toggle Result is %d\n",res_toggle);

	return 0;
}
//GET_N_BITS.
int getnbits(int num,int n,int p)
{
	unsigned char mask;
	int res;

	mask=(1<<n)-1; // For extracting the number of bits.

	mask=mask<<p; // Left shifting to the required Position.
	//res=num &((1<<n)-1)<<p
	res=(mask & num); //anding

	res=res>>p;// Right Shifing to extract only the no which were altered.

	return res;
}


//TOGGLE BITS.
int toggle(int num,int n,int p)
{
	unsigned int mask;
	int res;
	mask=(1<<n)-1;

	mask=mask<<p;

	res=(mask ^ num);

	return res;

}
