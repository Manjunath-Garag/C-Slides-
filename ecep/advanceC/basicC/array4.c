#include<stdio.h>

int main()
{
int idx;
int array_a[5]={1,2}; // few initializers.
int array_b[5]={10,20,30,40,50,60,70}; //excess intializers.

/*Printd array_a[]  */
for(idx=0;idx<5;idx++)
{
printf("array[%d]=%d\n",idx,array_a[idx]);
}

/* Prints array_b[]  */

printf("\n Elements in array_b=%d\n",(int)(sizeof(array_b)/(sizeof(array_b[0]))));

for(idx=0;idx<5;idx++)
{
printf("array[%d]=%d\n",idx, array_b[idx]);
}

return 0;
}
