#include<stdio.h>
#include<stdlib.h>
#include<sorts.h>

int main()
{
	int n,max,i;
	printf("Enter the size of the array\n");
	scanf("%d",&max);
	int a[max];
	int low=0;
	int high=max-1;
	printf("Enter the array elements\n");
	for(i=0;i<max;i++)
	{
		scanf("%d",&a[i]);
	}
	while(1)
	{
		printf("Enter your Choice\n1:Insertion\n2:Selection\n3:merge\n4:Print_array\n5:BUbble\n6:Quick Sort\n7:Heap_sort\n8:Merge_array\n9:Exit\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1: insertion(a,max);	//max is raw.
				break;

			case 2: selection(a,max);
				break;

			case 3:	merge_partition(a,low,high);
				for(i=0;i<max;i++)
					printf("%d\t",a[i]);
				break;

			case 4: print_array(a,max);
				break;

			case 5: bubble(a,max);
				break;

			case 6: quick_sort(a,low,high);
				for(i=0;i<max;i++)
					printf("%d\t",a[i]);
				break;

			case 7: heap_sort(a,max);
				break;

			case 8:merge_array();
			       break;

			case 9:exit(1);

		}
	}//while
}
