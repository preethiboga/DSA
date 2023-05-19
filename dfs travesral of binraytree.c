#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *right,*left;
}*root=NULL;
void inorder(struct node *root);
void insert(struct node *nn,struct node *root);
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);	
   }
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
   }
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
    	printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void insert(struct node *nn,struct node*root)
{
	if(nn->data<=root->data)
	{
		if(root->left==NULL)
		root->left=nn;
		else
		insert(nn,root->left);
	}	
	else
	{
		if(root->right==NULL)
		root->right=nn;
		else
		insert(nn,root->right);
	}
}
int main()
{
	struct node *nn;
	int choice;
	while(1)
	{
		printf("\n1.insert\n2.inorder\n3.postorder\n4.preorder\n5.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				nn=(struct node*)malloc(sizeof(struct node));
				nn->left=NULL;
				nn->right=NULL;
				printf("enter data:");
				scanf("%d",&nn->data);
				if(root==NULL)
				root=nn;
				else
				insert(nn,root);
				break;
			case 2:
			  inorder(root);
			  break;
			case 3:
			  postorder(root);
			  break;
			 case 4:
			   preorder(root);
			   break;
			 case 5:
			   exit(0);   
			default:
			  printf("invalid choice\n");    	
		}
	}
}
