#include<stdio.h>
#include<stdlib.h>
#include<bin_tree.h>

int main()
{
	int data,n,ans,ele;
	bs_tree *root =NULL;

	while(1)
	{
		printf("Enter your choice\n1:Insert_data\n2:Print_inorder\n3:find_min\n4:find_max\n5:Delete_ele\n6:Exit\n7:pre-order\n8:post-order\n9:Find_ele\n10:find_height\n11:find_roots\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("Enter the data\n");
			       scanf("%d",&data);//Root is NULL, there is no ele,
			       root = insert_data(root,data);//once a Data is added in the ".c" it return the address of the struct, which is accepted as a Root.
			       break;
			case 2: print_inorder(root);
				break;
			case 3:ans=find_min(root);//accptes the MIN.
			       printf("%d\n",ans);
			       break;
			case 4:ans=find_max(root);
			       printf("%d\n",ans);
			       break;
			case 5: printf("Enter the ele you want to delete\n");
				scanf("%d",&ele);
			case 7: print_preorder(root);
				break;
			case 6:exit(1);
			       break;
			case 8: print_postorder(root);
				break;

				printf("%p\n",root);
				root=tree_delete_ele(root,ele);
				printf("%p\n",root);
				if(root == NULL)
					printf("IN the main no ele was found\n");
				//printf("%d",ans);
				break;
			case 9: printf("Enter the elmentyou want to find\n");
				scanf("%d",&ele);
				//root=tree_find_ele(root,ele);
				tree_find_ele(root,ele);
				break;
			case 10:ans=find_height(root);
				printf("The height of the tree is %d\n",ans);
				break;
			case 11:ans=find_roots(root);
				printf("The no of NODES present in the tree is %d\n",ans);
				break;

			default:
				printf("Enter your correct choice\n");
		}

	}
}
