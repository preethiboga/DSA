#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
}*root=NULL;
void insert(struct node *nn,struct node *root);
void printtree(struct node *root);
void bfs(struct node *root);
int height(struct node *root);
void printcurrentlevel(struct node*root,int i);
void bfs(struct node *root);
int main()
{
	int choice,level;
	struct node *nn;
	while(1)
	{
		printf("1.insert\n2.display\n3.bfs\n4.givenlevel\n5.exit\n");
		printf("enter choice:");
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
				printtree(root);
				break;
			case 3:
				bfs(root);
				break;
			case 4:
			  printf("enter level:");
			  scanf("%d",&level);
			  printcurrentlevel(root,level);	
			case 5:
				exit(0);
			   break;
			default:
			 printf("invalid choice");  	
			    		
		}
	}
}
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
	   printf("%d ",root->data);
	   printtree(root->left);
       printtree(root->right);
    }
}
void bfs(struct node *root)
{
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
	printcurrentlevel(root,i);
	printf("\n");
}
void printcurrentlevel(struct node*root,int level)
{
	if(root==NULL)
	return;
	if(level==1)
	printf("%d ",root->data);
	else if(level>1)
	{
		printcurrentlevel(root->left,level-1);
		printcurrentlevel(root->right,level-1);
	}
}
int height(struct node *root)
{
	if(root==NULL)
	return 0;
	else
	{
		int lheight=height(root->left);
		int rheight=height(root->right);
		if(lheight>rheight)
		return(lheight+1);
		else
		return(rheight+1);
	}
}
