#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *nextptr
}*head;
void clcreation(int n);
void cldisplay();
void deletemiddle(int pos);
int main()
{
	int n,pos;
	head=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	clcreation(n);
	printf("before deletion:");
	cldisplay();
	printf("\n");
	printf("enter position to delete:");
	scanf("%d",&pos);
	deletemiddle(pos);
	printf("after deletion:");
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
void deletemiddle(int pos)
{
	int i;
	struct node *nodetodel,*temp;
	temp=head;
	nodetodel=head;
	for(i=2;i<=pos;i++)
	{
		temp=nodetodel;
		nodetodel=nodetodel->nextptr;
	}
	temp->nextptr=nodetodel->nextptr;
	free(nodetodel);
	
}

