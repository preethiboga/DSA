#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void display();
void createnode(int n);
int count();
int main()
{
	int n,c;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	display();
	printf("\n");
	c=count();
	printf("no.of node are %d",c);
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
		temp=newnode;
		
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
int count()
{
	int sum=0;
	struct node*temp;
		temp=head;
		while(temp!=NULL)
		{
			sum++;
			temp=temp->next;
		}	
	return sum;
}
