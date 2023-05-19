#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *prev;
 struct node *next;
}*head;
void createcdl(n);
void display();
int count();
int main()
{
	head=NULL;
	int n;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	createcdl(n);
	display();
	printf("\n");
	int c=count();
	printf("no.of nodes=%d",c);	
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
	temp2=head;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=head;
	head->prev=temp2;
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
int count()
{
	int c=0;
	struct node*temp;
	temp=head;
	do{
		c++;
		temp=temp->next;
	}while(temp!=head);	
	
	return c;	
}

