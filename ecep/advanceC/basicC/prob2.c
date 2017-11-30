#include<stdio.h>
/* Using ascending order and retriving the last value.  METHOD 1
   int main()
   {
   int array[5]={5,100,-2,75,42};
   int idx,jdx,temp=0;
   for(idx=0;idx<5;idx++)
   {
   for(jdx=idx+1;jdx<5;jdx++)
   {
   if(array[idx] > array[jdx])
   {
   temp=array[idx];
   array[idx]=array[jdx];
   array[jdx]=temp;
   }
   }
   }
   for(idx=0;idx<5;idx++)
   {
   printf("%d\n",array[idx]);
   }
   printf("%d\n",array[4]);
   return 0;
   }  */

/*  METHOD 2  */
int main()
{

	int array[5]={5,100,-2,750,42};
	int idx,largest;
	largest = array[0];
	for(idx=1;idx<5;idx++)
	{
		if(largest<array[idx])
		{
			largest=array[idx];
		}

	}
	printf("%d\n",largest);
return 0;
}


/*  Method 3  
largest=array[0];
for(i=1;i<5;i++)
{
	if(largest < a[i]) // if it is < then the smallest element will be searched.
	{	
		largest=a[i];
	}
}
printf("Largest =%d\n",largest);

*/
