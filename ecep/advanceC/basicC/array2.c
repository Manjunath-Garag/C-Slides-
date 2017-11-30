#include<stdio.h>

int main()
{
int array[5];
int idx;

// Assigning values to the array.
for(idx=0;idx<5;idx++) // idx<100 core dumped. boundries should not be exceded SEGMENTATION FAULT.
{
array[idx]=idx+1;
}

// printing the values of the array.
for(idx=0;idx<5;idx++)
{
printf("array[%d]=%d\n",idx,array[idx]);
}

return 0;
}
