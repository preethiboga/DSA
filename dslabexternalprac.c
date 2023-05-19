#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int  data;
	struct node *left;
	struct node *right;
}*root=NULL;
void printcurrentlevel(struct node *root,int level);
void bfs(struct node *root)
{
	int i,h;
	h=height(root);
	for(i=1;i<=h;i++)
	printcurrentlevel(root,i);
	printf("\n");
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
		return lheight+1;
		else
		return rheight+1;
	}
}
void printcurrentlevel(struct node *root,int level)
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
void display(struct node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("%d ",root->data);
		display(root->right);
	}
}
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
void main()
{
	int choice,level,h,dep,hd,hr,c,val;
	struct node *nn,*s,*d;
	while(1)
	{
		printf("1.insert\n2.display\n3.bfs\n4.givenlevel\n5.getheight\n6.getdepth\n7.count\n8.exit\n");
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
				bfs(root);
				break;
			case 4:
			 printf("enter level:");
			 scanf("%d",&level);
			 printcurrentlevel(root,level);
			 break;
			case 5:
			   printf("enter ele to get height");
			   scanf("%d",&h);
			   s=search(root,h);
			   if(s==NULL)
			   printf("not found");
			   else
			   {
			   h=height(s);
			   printf("height=%d",h-1);
		       }
			   break;
			case 6:
				printf("enter ele to get depth");
				scanf("%d",&dep);
				d=search(root,dep);
				if(d!=NULL)
				hd=height(d);
				hr=height(root);
				printf("depth=%d",(hd-1)-(hr-1));
				break;
			case 7:
				c=height(root);
				val=pow(2,c);
				printf("%d",val-1);
				break;	
		    case 8:
		   	   exit(0);
		   	   break;
			default:	
				printf("invalid choice");	     	
		}
	}
}
