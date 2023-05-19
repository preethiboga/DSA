#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *nextptr;
}*head;
void clcreation(int n);
void cldisplay();
void find(int element,int n);
int main()
{
	int n,element,c;
	head=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	clcreation(n);
	cldisplay();
	printf("\n");
	printf("enter element to search:");
	scanf("%d",&element);
	find(element,n);
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
void find(int element,int n)
{
	struct node *temp;
	int c=0,flag=0;
	if(head!=NULL && head->num==element)
	{
		flag=1;
		c=1;
		printf("element found at %d:",c);
	}
	else
	{
	    c=1;
		temp=head->nextptr;
		while(temp!=head)
		{
			c++;
			if(temp->num==element)
			{
				flag=1;
				printf("element found at %d:",c);
				break;
			}
			temp=temp->nextptr;
    	}
		
	}
	if(flag==0)
		{
			printf("not found");
		}
	

}

