#include<stdio.h>
#include<stdlib.h>
#include<binary.h>

int main()
{
	int n,key;
	int arr[5]={1,3,5,7,9};
	int low=0,high=4; //high=size-1

	while(1)
	{
		printf("Enter your Choice\n1:Bin_search\n2:Bin_serach_rec\n3:Exit\n");
		scanf("%d",&n);

		switch(n)
		{
			int ret;
			case 1: printf("Enter the key element to be Found\n");
				scanf("%d",&key);
				ret=bin_search(arr,5,key);
				printf("The ele was found at %d\n",ret);
				break;

			case 2: 
				printf("Enter the key element to be Found\n");
				scanf("%d",&key);
				ret=bin_rec(arr,high,low,key);	//arr,high,low,key_ele
				printf("The ele was found at %d\n",ret);
				break;	

			case 3:exit(1);
		}
	}
}
