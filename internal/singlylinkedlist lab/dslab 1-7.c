#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next
}*head;
void display();
void createnode(int n);
void del_begining();
struct node *create();
int main()
{
	int n,data,pos;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("before deletion:");
	display();
	printf("\n");
	del_begining();
	printf("after deletion :");
	display();
}
void createnode(int n)
{
	int data,i;
	struct node *temp,*newnode;
	head=create();
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=create();
		temp->next=newnode;
		temp=newnode;
	}	
}
struct node *create()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
	
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
void del_begining()
{
	struct node*todelfirst;
	if(head==NULL)
	{
		printf("no elements");
	}
	else
	{
		todelfirst=head;
	    head=head->next;
	    free(todelfirst);
	}
	
}


