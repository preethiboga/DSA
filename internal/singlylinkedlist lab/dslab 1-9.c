#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void display();
void createnode(int n);
void del_end();
int main()
{
	int n,data,pos;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("before deletion:");
	display();
	printf("\n");
	del_end();
	printf("after deletion :");
	display();
	return 0;
}
void createnode(int n)
{
	int data,i;
	struct node *temp,*newnode;
	head=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
	}	
}
void display()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("no elements");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void del_end()
{
	struct node *todellast,*prevnode;
	if(head==NULL)
	{
		printf("no elements");
	}
	else
	{
		todellast=head;
	    prevnode=head;
	    while(todellast->next!=NULL)
	    {
	    	prevnode=todellast;
	    	todellast=todellast->next;
		}
		if(todellast==head)
		{
			head=NULL;
		}
		else
		{
			prevnode->next=NULL;
		}
	    free(todellast);
	}
	
}


