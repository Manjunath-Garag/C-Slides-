
#include<stdio.h>

int getnbits(int num,int n,int p);// prototyping
int toggle(int num,int n,int p);
int setnbits(int value,int n,int p,int num);
int getbits(int num,int n);



int main()
{
	int num,p,n,result1,result2,result3,result4,result5;
	// unsigned char mask;
	int value;
		
	printf("Enter the number\n");
	scanf("%d",&num);

	printf("Enter the no of Bits to be extracted i.e mask\n");
	scanf("%d",&n);

	printf("Enter the Position from where it has to be extracted\n");
	scanf("%d",&p);
	
	printf("Enter the value for set_n_bits problem.\n");
	scanf("%d",&value);

		result1=getnbits(num,n,p);//Function call.
		result2=toggle(num,n,p);//Toggle
		result3=setnbits(value,n,p,num);		
		result4=getbits(num,n);
		result5=setbits(num,n,value);
	printf("The final Result is %d\n",result1);
	printf("The toggle Result is %d\n",result2);
	printf("The set_n_bits Result is %d\n",result3);
	printf("The getbits Result is %d\n",result4);
	printf("The setbits Result is %d\n",result5);

	return 0;
}
//GET_N_BITS. From a position.
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


//TOGGLE BITS.from a position
int toggle(int num,int n,int p)
{
	unsigned int mask;
	int res;
	mask=(1<<n)-1;

	mask=mask<<p;

	res=(mask ^ num);// XOR is used to TOGGLE.

	return res;
}


//Set_n_bits. from a position.
int setnbits(int value,int n,int p,int num)
{
	unsigned int mask,maskk;
	
	int result,res1,res2;

	mask=(1<<n)-1; // to extract the no of bits.

	mask=mask<<p; // from the Position.

	maskk=~mask; // ~ because we need to clear those bits.

	res1=(maskk & value); // this will clear those bits.

	res2=(mask & num); // here we are just getting the values of the required Bits.

	result= res1 | res2; // OR-ing will replace those bits.

	return result;
}



//Get n Bits without any Particular position. 
int getbits(int num, int n)
{
	int result;
	unsigned int mask;
	mask=(1<<n)-1;//formula to get_n_bits.

	result=(n & mask); // And-ing will give you the result
	return result;
}


int setbits(int num,int n, int value )
{
	int res1,res2;
	unsigned int mask;
	mask=(1<<n)-1;
	mask=~mask;//we are negating to  clear the bits.
	res1=(n&mask); // anding the ~mask and n

	res2=(res1 | value); // finally replacing it with the bits present in the value.
	printf("The final res is %d\n",res2);
}
