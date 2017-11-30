
#include<stdio.h>

int main()
{
int idx;
int array_a[5]={1,2,3,4,5};
int array_b[5]; // this is an empty array It is a VALID declaration. But array_b[] is INVALID.

//array_b = array_a;  // NOT POSSIBLE ERROR. NOT SUPPORTED arrays adress or size is fixed.
//array_a++; // lvalue required ERROR.

for(idx=0;idx<5;idx++)
{
array_b[idx]=array_a[idx]; //Copying Process
}


for(idx=0;idx<5;idx++)
{
printf("%d,%d\n",array_a[idx],array_b[idx]); // printing each array element 
}
return 0;
}
