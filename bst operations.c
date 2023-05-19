#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
}*root=NULL;
void insert(struct node *nn,struct node *root);
void printtree(struct node *root);
struct node *searchnode(int ele,struct node *root);
struct node *parent(struct node *n,struct node *root);
void deletenode(struct node *n);
struct node *getsuccessor(struct node *n);
void insert(struct node *nn,struct node *root)
{
	if(nn->data<=root->data)
	{
		if(root->left==NULL)
		{
			root->left=nn;
		}
		else
		{
			insert(nn,root->left);
		}
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=nn;
		}
		else
		{
			insert(nn,root->right);
		}
	}
}
void printtree(struct node *root)
{
	if(root!=NULL)
	{
		printtree(root->left);
		printf("%d\n",root->data);
		printtree(root->right);
	}
}
struct node *searchnode(int ele,struct node *root)
{
	if(root->data==ele)
	{
		return root;
	}
	else
	{
		if(ele<=root->data)
		{
			if(root->left==NULL)
			{
				return NULL;
			}
			else
			{
				searchnode(ele,root->left);
			}
		}
		else
		{
			if(root->right==NULL)
			{
				return NULL;
			}
			else
			{
				searchnode(ele,root->right);
			}
		}
	}
}
struct node *parent(struct node *n,struct node *root)
{
	if(n->data<=root->data)
	{
		if(root->left->data==n->data)
		{
			return root;
		}
		else
		{
			parent(n,root->left);
		}
	}
	else
	{
		if(root->right->data==n->data)
		{
			return root;
		}
		else
		{
			parent(n,root->right);
		}
	}
}
void deletenode(struct node *n)
{
	int x;
	struct node *p,*succ;
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
		{
			root=NULL;
		}
		else
		{
			p=parent(n,root);
			if(p->left==n)
			{
				p->left=NULL;
			}
			else
			{
				p->right=NULL;
			}
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
	if(n->left==NULL && n->right!=NULL)
	{
		x=n->right->data;
		deletenode(n->right);
		n->data=x;
	}
}
struct node *getsuccessor(struct node *n)
{
	if(n->left==NULL)
	{
		return n;
	}
	else
	{
		getsuccessor(n->left);
	}
}
int main()
{
	struct node *nn,*s,*d;
	int choice,ele,del;
	while(1)
	{
		printf("1.insert\n2.search\n3.delete\n4.printtree\n5.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				nn=(struct node*)malloc(sizeof(struct node));
				nn->right=NULL;
				nn->left=NULL;
				printf("enter data:");
				scanf("%d",&nn->data);
				if(root==NULL)
				{
					root=nn;
				}
				else
			    {
				    insert(nn,root);
			    }
				break;
			case 2:
			  printf("enter element to search:");
			  scanf("%d",&ele);
			  if(root==NULL)
			  {
			  	s=NULL;
			  }
			  else
			  {
			  	s=searchnode(ele,root);
			  }
			  if(s==NULL)
			  {
			  	printf("not found\n");
			  }
			  else
			  {
			  	printf("node exist\n");
			  }
			  break;
			case 3:
			   printf("enter node to del:");
			   scanf("%d",&del);
			   if(root==NULL)
			   {
			   	printf("empty\n");
			   }
			   else
			   {
			   	  d=searchnode(del,root);
			   	  if(d==NULL)
			   	  {
			   	 	printf("not found\n");
				  }
			    	else
				  {
					deletenode(d);
				  }
			   }
			   break;
			case 4:
				printtree(root);
				break;
			case 5:
			   exit(0);  
			 default:
			   printf("invalid choice\n");    
		}
	}
}
