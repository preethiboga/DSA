#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int data;
	struct node *left,*right;
}*root=NULL;
void insert(struct node *nn,struct node *root);
void printtree(struct node *root);
struct node *searchnode(int ele,struct node *root);
int getheight(struct node *n);
int getdepth(int n,struct node *root);
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
int getheight(struct node *n)
{
	if(n==NULL)
	return 0;
	int lheight=getheight(n->left);
	int rheight=getheight(n->right);
	if(lheight>rheight)
	return (lheight+1);
	else
	return (rheight+1);
}
int main()
{
	struct node *nn,*s,*d,*hi;
	int choice,x,h,y,dep,ele,c,val;
	while(1)
	{
		printf("1.insert\n2.search\n3.getheight\n4.printtree\n5.depth\n6.count\n");
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
			  	printf("empty");
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
			   printf("enter node to get height:");
			   scanf("%d",&h);
			   hi=searchnode(h,root);
			   if(hi==NULL)
			   {
			   	printf("not found\n");
			   }
			   else
			   {
			   	printf("height=%d",getheight(hi)-1);
			   }
			   break;
			case 4:
				printtree(root);
				break;
			case 5:
				printf("enter node to get depth:");
			   scanf("%d",&dep);
			   d=searchnode(dep,root);
			   if(d==NULL)
			   {
			   	printf("not found");
			   }
			   else
			   {
			   	 x=getheight(root);
			   	 y=getheight(d);
			   	 printf("depth=%d",(x-1)-(y-1));
			   } 
			  break ; 
			 case 6:
			 	c=getheight(root);
			 	val=pow(2,c);
			 	printf("count=%d",val-1);
			 	break;   
			 default:
			   printf("invalid choice\n");    
		}
	}
}
