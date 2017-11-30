#include<stdio.h>

void print_array(int *a,int size)
{
	int i;
	for(i=0;i<size; i++)
	{
		printf("%d\t",a[i]);
	}printf("\n");
	return;
}

void bubble(int *a, int size)		//size is raw not max-1.
{
	int temp;
	int i,j,n;
	printf("Enter your choice\n1:ascending\n2:descending\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1 :
			for(i=0;i<size-1;i++) //Iteration,
				{
					for(j=0;j<size-i-1;j++) //for traversing inbetween the list.
					{//adjustent elements(j,j+1) are compared and In every Iteration Largest element moves to the END.
						if(a[j] > a[j+1])
						{
							temp=a[j];
							a[j]=a[j+1];
							a[j+1]=temp;
						}
					}
				}print_array(a,size);
			break;

		case 2 :
			for(i=0;i<size-1;i++) //Iteration,
				{
					for(j=0;j<size-i-1;j++) //for traversing inbetween the list.
					{
						if(a[j] < a[j+1])
						{
							temp=a[j];
							a[j]=a[j+1];
							a[j+1]=temp;
						}
					}
				}print_array(a,size);
			break;
	}
}
void insertion(int *a,int size) //i starts from 1 and j=0 i value are compared with j values. if i=5 , j=4,3,2,1 values are compared.
{
	int i,j,value,n;
	printf("Enter your choice\n1:ascending\n2:descending\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1 :
			for(i=1;i<size;i++)	//i starts from 1 .
			{
				value=a[i];
				j=i-1;	//assigning the J value. // j=i-1 = 0.checks the ele towards the left of "i".
				while(j>=0 && value < a[j])
				{
					a[j+1] = a[j];	//replacing the a[j+1]'st Position.
					j--;
				}		//goes out of the loop only when j is -1. OR whe the 2nd condtion fails.
				a[j+1]=value;	//assigning the value to a[j+1]
			}
			print_array(a,size);
			break;

		case 2 :
			for(i=1;i<size;i++)	//i starts from 1 .
			{
				value=a[i];
				j=i-1;	//assigning the J value. // j=i-1 = 0.
				while(j>=0 && value > a[j])
				{
					a[j+1] = a[j];	//replacing the a[j+1]'st Position.
					j--;
				}		//goes out of the loop only when j is -1. OR whe the 2nd condtion fails.
				a[j+1]=value;	//assigning the value to a[j+1]
			}
			print_array(a,size);
			break;
	}//switch
}//insertion.

void selection(int *a,int size)// IN SEL sort we find the least min element in the Array and put it in the i'th Postion or 0th Position.
{
	int i,j,min,temp,n,max;
	printf("Enter your choice\n1:ascending\n2:descending\n");
	scanf("%d",&n);
	switch(n)	//Most min ele is bought to the 1st pos
	{
		case 1:
			for(i=0;i<size-2;i++)	//size or size-2
			{
				min=i;
				for(j=i+1;j<size;j++)
				{
			//considering the 1st element INDEX as the min and comparing it with UP-comming values.
					if(a[min] > a[j])		//> for Ascending if 6 > 5 then index of 5 is min.
					{ //if cond we are trying to FIND the new MIN. 5 > 3 3 is the new MIN.
						min=j;	//We just Consider the INdex of 3.
					}
				} //once min is found it is SAWPed with a[i] i.e a[0],a[1]......
				temp = a[i];
				a[i]=a[min];
				a[min]=temp;	//swap.
			}
			print_array(a,size);
			break;

		case 2:
			for(i=0;i<size;i++)
			{
				max=i;
				for(j=i+1;j<size;j++)
				{//considering the 1st element INDEX as the min and comparing it with UP-comming values.
					if(a[max] < a[j])		//<for Descinding if 6 < 5 then False.
					{//100 < 200 200 is the new MAX.
						max=j;	// we just consider the INdex of 200.
					}
				} //once min is found it is SAWPed with a[i] i.e a[0],a[1]......
				temp = a[i];
				a[i]=a[max];
				a[max]=temp;	//swap.
			}
			print_array(a,size);
			break;
	}
}

//MERGE SORT
void merge_sort(int *a,int low,int high)
{
	int i,j;
	int k=0;
	int mid;
	mid=(low+high)/2;
	i=low;	//new i value 
	j=mid+1;
	int temp[high-low +1];	//a temp array to copy the Sorted Arrray. As the same size of that of the Array.
	while( (i<=mid) && (j<=high) )
	{ 
		if(a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++]=a[j++];
	}//1st while

	while(j<=high) //if "i" array elements are less(OVER) the remaining "j" array elements has to be Copied.
		temp[k++]=a[j++]; 

	while(i<=mid) //if "j" array elements are less the remaining "i" array elements has to be Copied.
		temp[k++]=a[i++];  

	k=0; //k has to at the initial Position 

	for(i=low;i<=high;i++)  	//actuall poistion in the array willbe swapped since the range is low to high, l and h changes each time in each iteration.
		a[i] = temp[k++];

}

void merge_partition(int *a,int low,int high)
{
	int mid;
	if(low < high) //if low =high there will be only 1 element and Partition has to Stop. MID will also be at the same position
	{
		mid=(low+high)/2;
		merge_partition(a,low,mid);	//consider l=2,h=2 then while calling mer_par for (mid+1,high),low will cross  high.
		merge_partition(a,mid+1,high);
		merge_sort(a,low,high);
	}
}

//QUICK SORT.
int partition(int *arr, int low, int high);
void quick_sort(int *arr, int low, int high)
{
	int split;
	if(low < high)// 0 < 0 comdtion fails then the called Quick sort will return and execute the remaining code below it.
	{
		split = partition(arr, low, high);//return value is used just to split the array.
		//left side
		quick_sort(arr, low, split - 1);	//chunk by chunk it is sorting.
		//right side
		quick_sort(arr, split, high);
	}
}

int partition(int *arr, int low, int high)//partition will return the lft value.
{	//unlike MERGE sort we return the left value, that will act as mid.
	int pivot = arr[low];
	int left = low;
	int right = high;
	int  temp;
	while(left <= right)
	{
		while(arr[left] < pivot && left <= right)	//5<6 left++ consider 6 as Pivot
			left++;
		while(arr[right] > pivot && left <= right)	//7>6 right--
			right--;
		if(left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			left++;
			right--;
		}
	}
	return left;//once Cross over is done Return Left.
}

//HEAP SORT
void max_heapify(int *arr,int size, int parent);
void heap_sort(int *arr,int size)
{
	int i;
	for(i=(size/2)-1; i>=0; i--)	//starts from the last Parent. we are passing the INDEX for the Parent.
	{
		max_heapify(arr,size,i);	//if 4 parents are there,then the parents are called from the LAST 3,2,1,0. 0th parent is the root.
	} //after this loop gets over,the elements are arranged as a Perfect BInary Tree format. and is Ready to get swapped in the next FOR-LOOP, i.e the ROOT and LAST element of the TREE.

	for(i=size-1; i>0; i--)		//swaping the root and last ele of the tree.
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i]=temp;//after swapping, the tree will not be in the BINARY-TREE-FORMAT, so again we call max-heapify();

		max_heapify(arr,i,0);//after swapping max-heapify(arr,size-1,0) just like deleting the Highest ele.

	}print_array(arr,size);

}

void max_heapify(int *arr,int size, int parent)
{
	int left,right,max;
	left = 2 * parent + 1;
	right = 2 * parent + 2;
	max=parent;
	if( (arr[left] > arr[max]) && (left < size) )	//comparing the left ele with the Parent.
		max = left;

	if( (arr[right] > arr[max]) && (right < size) )	//the also comparing the Right ele with the Parent.
		max = right;
	//out of the above 2 IF-Condtions we get the max value and and it will be replaced as parent in the below if Condition.

	if(max != parent)	//if max is NOt changed i.e (1 != 1) <= index.
	{
		int temp = arr[max];	//in max_heapify function, we swap cos, we need to get the tree in BST format.
		arr[max] = arr[parent];
		arr[parent]=temp;	//where-as in heap-sort we swap to eliminate the highest element.

		max_heapify(arr,size,max);	//once it is swapped, the BST format is gone so again, we call max_heapify.
	}

}

void merge_array()
{
	int size1,size2,i,j,k;
	printf("Enter the size of 2 arrays\n");
	scanf("%d%d",&size1,&size2);

	int arr1[size1];
	int arr2[size2];
	k=(size1 + size2);
	int temp[k];
	printf("Enter the 1st array elements\n");
	for(i=0;i<size1;i++)
		scanf("%d",&arr1[i]);

	printf("Enter the 2nd array elements\n");
	for(j=0;j<size2;j++)
		scanf("%d",&arr2[j]);

	selection(arr1,size1);
	selection(arr2,size2);
	printf("After sorting the 2 arrays\n");
	for(i=0;i<size1;i++)
		printf("%d\t",arr1[i]);
	printf("\n");
	for(j=0;j<size2;j++)
		printf("%d\t",arr2[j]);

	i=0;// the valuess will be scattered hence it has to initialised to 0.
	j=0;
	k=0;
	while(i<size1)
		temp[k++]=arr1[i++];

	while(j<size2)
		temp[k++]=arr2[j++];

	quick_sort(temp,0,k-1);

	printf("\nAfter sorting the complete array\n");
	for(i=0;i<k;i++)
	{
		printf("%d\t",temp[i]);
	} 

}
