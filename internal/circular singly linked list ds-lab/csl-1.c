#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *nextptr
}*head;
void clcreation(int n);
void displaycllist();
void reverse(struct node *head);
void rev();
int main()
{
	int n;
	head=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	clcreation(n);
	displaycllist();
	rev();
	return 0;
}
void clcreation(int n)
{
	int num,i;
	struct node *newnode,*preptr;
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
void displaycllist()
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
void rev()
{
   struct node *temp=head;
   while(temp->nextptr!=head)
   {
   	temp=temp->nextptr;
   }
   temp->nextptr=NULL;
   reverse(head);
}
void reverse(struct node *head)
{
	if(head==NULL)
	return;
	else
	{
		reverse(head->nextptr);
		printf("%d ",head->num);
	}
}



