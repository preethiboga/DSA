#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void display();
void createnode(int n);
void insert_begining(int data);
int main()
{
	int n,data;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("before inserting:");
	display(); 
	printf("\n");
	printf("enter data to insert:");
	scanf("%d",&data);
	insert_begining(data);
	printf("after inserting:");
	display();
}
void createnode(int n)
{
	struct node *newnode,*temp;
	int data,i;
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
			printf("%d " ,temp->data);
			temp=temp->next;
		}
	}
}
void insert_begining(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=head;
	head=newnode;
	
}
