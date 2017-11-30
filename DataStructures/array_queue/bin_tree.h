#ifndef BIN_TREE_H
#define BIN_TREE_H

typedef struct tree
{
	int data;
	struct tree *left,*right;
}bs_tree;

bs_tree *insert_data(bs_tree *root,int data);
int find_min(bs_tree *root);
int find_max(bs_tree *root);
void print_inorder(bs_tree *root);
bs_tree *tree_delete_ele(bs_tree *root,int ele);
int find_roots(bs_tree *root);
int find_height(bs_tree *root);
bs_tree *tree_find_ele(bs_tree *root,int ele);
bs_tree *tree_delete_ele(bs_tree *root,int ele);

#endif
