#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *prev;
 struct node *next;
}*head;
void createcdl(n);
void display();
int main()
{
	head=NULL;
	int n;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	createcdl(n);
	display();	
	return 0;
}
void createcdl(n)
{
	struct node *newnode,*temp,*temp2;
	head=(struct node*)malloc(sizeof(struct node));
	int data,i,j;
	printf("enter data:");
	scanf("%d",&data);
	head->data=data;
	head->prev=NULL;
	head->next=NULL;
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&data);
		newnode->data=data;
	    newnode->next=NULL;
	    newnode->prev=temp;
	    temp->next=newnode;
	    temp=newnode;
	}
	temp->next=head;
	head->prev=temp;
}
void display()
{
	struct node *temp;
	temp=head;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	
}

