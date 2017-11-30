#include<stdio.h>

int main()
{
int array_a[5]={1,2,3,4,5};
int array_b[5]; // this is an empty array It is a VALID declaration. But array_b[] is INVALID.

//array_b = array_a;  // NOT POSSIBLE ERROR. NOT SUPPORTED arrays adress or size is fixed.
//array_a++; // lvalue required ERROR.

printf("%p, %p\n", array_a,array_b); // return the address in hexa
printf("%d, %d\n", array_a,array_b); // return the address in decimal.
if(array_b ==array_a)  //Address is compared. They are different they don't match.
{
printf("Copied.");
}

return 0;
}
