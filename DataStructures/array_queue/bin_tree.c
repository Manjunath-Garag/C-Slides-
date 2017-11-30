#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int data;
	struct tree *left,*right;
}bs_tree;

bs_tree *create_node(int data)
{
	bs_tree *new =malloc(sizeof(bs_tree));
	if(new == NULL)
		printf("Memory Problem in CPU\n");
	else
	{
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		return new;///retutning the Complete Structure Address.(1000)
	}
}

bs_tree *insert_data(bs_tree *root,int data)	//Insert Data in Binary search Format, with the help of LINE 30 and 32.
{
	if(root == NULL)
		return create_node(data);//for very 1st time it is returned to MAin and it is stored.
	else
	{
		if(data > root->data)
			root->right = insert_data(root->right, data);//if insert_data returns some addr then it will stored on right-node.
		else if(data < root->data)
			root->left = insert_data(root->left, data);
		else
			printf("Error:Duplicates\n");
	}
	return root;//returns ROOT because the list is Sorted based on the Root. and thr root->left or root->right would be UP-dated.
}//ret root zreturns The Complelete Structure. OR base address of the structure is is sent.

void print_inorder(bs_tree *root)	//L P R		//ASCENDING ORDER.
{
	if(root != NULL)
	{
		print_inorder(root->left);
		printf("%d\t",root->data);
		print_inorder(root->right);
	}
}

void print_preorder(bs_tree *root)	//P L R 
{
	if(root != NULL)
	{
		printf("%d\t",root->data);
		print_preorder(root->left);
		print_preorder(root->right);
	}
}

void print_postorder(bs_tree *root)	//L R P
{
	if(root != NULL)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%d\t",root->data);
	}
}

int find_min(bs_tree *root)
{
	if(root->left != NULL)
		return find_min(root->left);
	else
		return root->data;//recursively reaches the last left node return the data to main.
}

int find_max(bs_tree *root)
{
	if(root->right != NULL)
		return find_max(root->right);
	else
		return root->data;//recursive untill the root->right == NULL, then we return that data (root)
}

bs_tree *tree_delete_ele(bs_tree *root,int ele)
{
	bs_tree *temp;

	if(root == NULL)
	{
		printf("List is empty\n");
		return root;// null will be returned.
	} 
	if(root->data < ele)
		root->right = tree_delete_ele(root->right,ele);

	else if(root->data > ele)
		root->left = tree_delete_ele(root->left,ele);

	else //we enter thus condtion when we find the element.
// If there is ONLY one CHILD for the Parent = if or the else-if part would be exectuted, if it has both the childern then else part would be executed.
	{
		if(root->left == NULL)	//enters if root->left is null and root->right id present.
		{
			temp=root->right;//root->right's Address is stored in temp.
			free(root); //we are freeing that ele.
			return temp;//return to the Previous call and links the with that element.
		}
		else if(root->right == NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			int val =find_min(root->right);//to find the min ele on the Right Side. RULE.
			root->data=val;//over-ridding that value with MIN-VALUE.
			root->right=tree_delete_ele(root->right,val);//ltr delete that min data on the RiGHT(which was fetched. to be replaced)has to be Deleted 
			//the Above line a, due to delete_ele function a Complete del reucr funtion is called again.
		} 
	}
	return root;///returning the Complete Structure.
}//return root means ADDRESS, return 200 means it goes to the stack frame with address 200.


bs_tree *tree_find_ele(bs_tree *root,int ele)
{
	if(root == NULL)
	{//it will enter this loop if the ele was NOT found and returns back to the called function.
		printf("Element not found\n");
		return root;// null will be returned to the prevoius call and not the main.
	}
	if(root->data < ele)
		root->right = tree_find_ele(root->right,ele);

	else if(root->data > ele)
		root->left = tree_find_ele(root->left,ele);

	else //we enter thus condtion when we find the element. If there is ONLY one CHILD for the Parent.
		printf("The ele was found:%d\n",root->data);

	return root;//returning root is a MUST, becaues it is a Recursive Function.
}

int find_height(bs_tree *root)
{
	if(root == NULL)
		return 0;

	int left_height = find_height(root->left);
	int right_height = find_height(root->right);
	// return 1 + max(left,right);
	if(left_height > right_height)	//returns the max height of the 2 child nodes.
		return (left_height + 1);
	else
		return (right_height + 1);
}

int find_roots(bs_tree *root)	//to find the no of edges in the Tree.
{
	if(root == NULL)
		return 0;
	else
	{
		int left_height = find_roots(root->left);
		int right_height = find_roots(root->right);
		return (left_height + right_height + 1);
	}
}

