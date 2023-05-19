#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *nextptr
}*head;
void clcreation(int n);
void cldisplay();
void insertbegin(int num1);
int main()
{
	int n,num1;
	head=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	clcreation(n);
	printf("before insertion:");
	cldisplay();
	printf("\n");
	printf("enter data to insert:");
	scanf("%d",&num1);
	insertbegin(num1);
	printf("after insertion:");
	cldisplay();
	return 0;
}
void clcreation(int n)
{
	struct node *newnode,*preptr;
	int i,num;
	head=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&num);
	head->num=num;
	head->nextptr=NULL;
	preptr=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&num);
		newnode->num=num;
		newnode->nextptr=NULL;
		preptr->nextptr=newnode;
		preptr=newnode;
	}
	preptr->nextptr=head;
}
void cldisplay()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("no data");
	}
	else
	{
		temp=head;
		do
		{
			printf("%d ",temp->num);
			temp=temp->nextptr;
		}while(temp!=head);
	}
}
void insertbegin(int num1)
{
	struct node *newnode,*curnode;
	if(head==NULL)
	{
		printf("no data");
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->num=num1;
		newnode->nextptr=head;
		curnode=head;
		while(curnode->nextptr!=head)
		{
			curnode=curnode->nextptr;
		}
		curnode->nextptr=newnode;
		head=newnode;
	}
}

