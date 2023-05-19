#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node *create()
{
	int x;
	struct node *nn;
	printf("enter data(-1 for no data):");
	scanf("%d",&x);
	if(x==-1)
	return NULL;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	printf("enter left child %d:\n",x);
	nn->left=create();
	printf("enter right child %d:\n",x);
	nn->right=create();
	return nn;
}
void preorder(struct node *root)
{
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	struct node *root;
	root=create();
	printf("preorder traversal of tree is:");
	preorder(root);
	return 0;
}
