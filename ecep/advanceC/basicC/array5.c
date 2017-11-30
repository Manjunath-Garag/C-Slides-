/* ASSIGNMENT ERROR    if array[] or array[n]  */

#include<stdio.h>

int main()
{
int array[5];
int idx;

for(idx=0;idx<5;idx++)
{
printf("Enter the values of the array %d:",idx);
scanf("%d",&array[idx]); //DOUBT.   location is :array[0]....
}

for(idx=0;idx<5;idx++)
{
printf("array[%d]=%d\n",idx,array[idx]);
}

return 0;
}
