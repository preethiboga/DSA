#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next
}*head;
void display();
void createnode(int n);
void insert_middle(int data,int pos);
int main()
{
	int n,data,pos;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("before inserting:");
	display();
	printf("\n");
	printf("enter data to insert:");
	scanf("%d",&data);
	printf("enter position to insert:");
	scanf("%d",&pos);
	if(pos>1 && pos<n)
	{
		insert_middle(data,pos);
	}
	else
	{
		printf("insertion not possible");
	}
	printf("\n");
	printf("after inserting:");
	display();
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
void insert_middle(int data,int pos)
{
	int i;
	struct node *temp,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	temp=head;
	for(i=2;i<=pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	
}


