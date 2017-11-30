#include<stdio.h>
#include<stdlib.h>
#include<project.h>

int main(int no, char **file_name)
{
	node *arr[26]={0};	//2d-array. Alphabets
	int i, op;
	char name[32];
	while(1)
	{
		printf("Enter the option:\n");
		printf("1.Create-hash_table\n2.Search_word\n3.Print_hash_table\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				{

					for(i = 1 ; i < no ; i++)
					{
						FILE *fp = fopen(file_name[i], "r+");
						if(fp == NULL)
							printf("Sorry ! no file\n");
						else
							file(fp , arr , file_name[i]);
					}
				}
				break;
			case 3:
				{
				       for(i = 0 ; i < 26 ; i++)
					       print_details(arr[i] , no);

			       }
			       break;
			case 4:exit(1);
			default:printf("Try Again\n");
		}//switch
	}//while
}



























				/*	printf("Enter the file name\n");
					scanf("%s",file_name);
					fp=fopen(file_name,"r");
					if(fp == NULL)
					printf("NO File Avail\n");

					file( fp, arr,file_name );	//arr is a Double Pointer.

					for(i=0;i<26;i++)
					print_links(arr[i]);//this is a Single Pointer.
				 */
