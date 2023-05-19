#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *preptr;
	struct node *nextptr;
}*head,*ennode;
void createdl(int n);
void display();
void insertmiddle(int num1,int pos,int n);
int main()
{
	int n,num1,pos;
	head=NULL;
	ennode=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	createdl(n);
	printf("before inserting:");
	display();
	printf("\n");
	printf("enter number to insert at middle:");
	scanf("%d",&num1);
	printf("enter position:");
	scanf("%d",&pos);
	insertmiddle(num1,pos,n);
	printf("\n");
	printf("after inserting:");
	display();
	return 0;
}
void createdl(int n)
{
	int num,i;
	struct node *fnnode;
	if(n>=1)
	{
		head=(struct node*)malloc(sizeof(struct node));
		if(head!=NULL)
		{
			printf("enter data:");
			scanf("%d",&num);
			head->num=num;
			head->preptr=NULL;
			head->nextptr=NULL;
			ennode=head;
			for(i=2;i<=n;i++)
			{
				fnnode=(struct node*)malloc(sizeof(struct node));
				if(fnnode!=NULL)
				{
					printf("enter data:");
					scanf("%d",&num);
					fnnode->num=num;
					fnnode->preptr=ennode;
					fnnode->nextptr=NULL;
					ennode->nextptr=fnnode;
					ennode=fnnode;
				}
				else
				{
					printf("memory not allocted:");
					break;
				}
			}
		}
	}
		else
		{
			printf("memory not allocted");
		}
}
void insertmiddle(int num1,int pos,int n)
{
   if(pos>n)
	{
		printf("invalid position");
	}
	else
	{
	int i;
	struct node *newnode,*temp;
	if(ennode==NULL)
	{
		printf("no data found");
	}
	else
   {
		temp=head;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->num=num1;
		newnode->nextptr=NULL;
		newnode->preptr=NULL;
		for(i=2;i<pos-1;i++)
		{
			temp=temp->nextptr;
		}
		temp->nextptr->preptr=newnode;
		newnode->nextptr=temp->nextptr;
		newnode->preptr=temp;
		temp->nextptr=newnode;
	}
  }
}

void display()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("no data found");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->num);
			temp=temp->nextptr;
		}
	}
}

