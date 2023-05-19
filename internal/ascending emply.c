#include<stdio.h>
#include<stdlib.h>
struct node{
	char name[30];
	int id;
	int rate;
	struct node *next;
}*head=NULL;
void create(n);
struct node *createnode();
void display();
void insert();
int main()
{
	int n;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	create(n);
	display();
	insert();
	display();
}
void create(int n)
{
	int i;
	struct node *nn,*temp;
	nn=createnode();
	head=nn;
	temp=head;
	for(i=2;i<=n;i++)
	{
		nn=createnode();
		temp->next=nn;
		temp=nn;	
	}
}
struct node *createnode()
{
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter name:");
	scanf("%s",nn->name);
	printf("enter id:");
	scanf("%d",&nn->id);
	printf("enter rate:");
	scanf("%d",&nn->rate);
	nn->next=NULL;
	return nn;
}
void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		
		   printf("name:%s  id:%d  rating:%d\n",temp->name,temp->id,temp->rate);
	    temp=temp->next;
	}
}
void insert()
{
	struct node *n,*temp;
	printf("enter data to insert:\n");
	n=createnode();
	temp=head;
	if(head==NULL || head->rate>n->rate)
	{
		n->next=head;
		head=n;	
	}
	else
	{
	while(temp->next!=NULL && temp->next->rate<=n->rate)
	{
		temp=temp->next;
	}
	n->next=temp->next;
	temp->next=n;
}
	
}
