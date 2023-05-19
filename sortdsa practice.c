#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
}*root=NULL;
struct node *parent(struct node *root,struct node *n);
struct node *getsuccessor(struct node *n);
void insert(struct node *root,struct node *nn)
{
	if(nn->data<=root->data)
	{
		if(root->left==NULL)
		root->left=nn;
		else
		insert(root->left,nn);	
	}
	else
	{
		if(root->right==NULL)
		root->right=nn;
		else
		insert(root->right,nn);
	}
}
struct node *search(struct node *root,int ele)
{
	if(root->data==ele)
	return root;
	if(ele<=root->data)
	{
		if(root->left==NULL)
		return NULL;
		else
		search(root->left,ele);
	}
	else
	{
		if(root->right==NULL)
		return NULL;
		else
		search(root->right,ele);
	}
}
void display(struct node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("%d",root->data);
		display(root->right);
	}
	printf("\n");
}
void deletenode(struct node*n)
{
	struct node *succ;
	struct node *p;
	int x;
	if(n->left!=NULL && n->right!=NULL)
	{
		succ=getsuccessor(n->right);
		x=succ->data;
		deletenode(succ);
		n->data=x;
		return;	
	}
	if(n->left==NULL && n->right==NULL)
	{
		if(n==root)
		root=NULL;
		else
		{
			p=parent(root,n);
			if(p->left==n)
			p->left=NULL;
			else
			p->right=NULL;
		}
		free(n);
		return;
	}
	if(n->left!=NULL && n->right==NULL)
	{
		x=n->left->data;
		deletenode(n->left);
		n->data=x;
	}
	if(n->right!=NULL && n->left==NULL)
	{
		x=n->right->data;
		deletenode(n->right);
		n->data=x;
	}
}
struct node *getsuccessor(struct node *n)
{
	if(n->left==NULL)
	return n;
	else
	getsuccessor(n->left);
}
struct node *parent(struct node *root,struct node *n)
{
	if(n->data<=root->data)
	{
		if(root->left->data==n->data)
			return root;
		else
		   parent(root->left,n);	
	}
	else
	{
		if(root->right->data==n->data)
		     return root;
		else
		  parent(root->right,n);     	
	}
}
void main()
{
	int choice,ele,del;
	struct node *nn,*s,*d;
	while(1)
	{
		printf("1.insert\n2.display\n3.search\n4.delete\n5.exit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				nn=(struct node*)malloc(sizeof(struct node));
				printf("enter data:");
				scanf("%d",&nn->data);
				nn->left=NULL;
				nn->right=NULL;
				if(root==NULL)
				root=nn;
				else
				insert(root,nn);
				break;
			case 2:
			   display(root);
			   break;
			case 3:
			    printf("enter ele to search:");
				scanf("%d",&ele);
				s=search(root,ele);
				if(s==NULL)
				printf("not found");
				else
				printf("found");
				break;
			case 4:
			    printf("enter ele to del:");
				scanf("%d",&del);
				d=search(root,del);
				if(d==NULL)
				printf("not found");
				else
				deletenode(d);
				break;
			case 5:
			  exit(0);
			 default:
			   printf("invalid choice"); 		   	
		}
	}
}
