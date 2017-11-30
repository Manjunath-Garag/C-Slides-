#include<stdio.h>

int main()
{
	int idx,jdx,found;
	int array_a[3]={2,-50,17};
	int array_b[3]={17,2,-50};

	for(idx=0;idx<3;idx++)
	{
		found=0;
		for(jdx=0;jdx<3;jdx++)
		{
			//for(idx=0,jdx=0; idx<3; idx++,jdx++)

			if(array_a[idx] == array_b[jdx])
			{
				found=1;
				break;				// printf("Array elements are Equal\n");we should not use it here.
			}


		}
		if(!found) // even if one element in the array is not matching, it breaks the idx loop.
		{
			break;	
		}

	}
	if(found)
	{
		printf("Equaal\n");
	}
	else
	{
		printf("Unequal\n");
	}
	return 0;
}
