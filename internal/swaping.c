#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL;
void create(int n);
void display();
void swap();
int main()
{
	int n;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	create(n);
	display();
	swap();
	display();
}
void create(int n)
{
	int i;
	struct node *nn,*temp;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&nn->data);
	nn->next=NULL;
	head=nn;
	temp=head;
	for(i=2;i<=n;i++)
	{
		nn=(struct node*)malloc(sizeof(struct node));
    	printf("enter data:");
    	scanf("%d",&nn->data);
	    nn->next=NULL;
	    temp->next=nn;
	    temp=nn;
	}	
}
void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void swap()
{   int d1,d2,flag1=0,t,flag2=0;
    printf("enter 1st data to swap:");
	scanf("%d",&d1);
	printf("enter 2nd data to swap:");
	scanf("%d",&d2);
	struct node *temp,*s1,*temp2,*s2;
	temp=head;
	temp2=head;
	while(temp!=NULL)
	{
		if(temp->data==d1)
		{
			s1=temp;
			flag1=1;
			break;
		}
		temp=temp->next;
	}
	while(temp2!=NULL)
	{
		if(temp2->data==d2)
		{
			s2=temp2;
			flag2=1;
			break;
		}
		temp2=temp2->next;
	}
	if(flag1==0 || flag2==0)
	{
		printf("not found");
	}
	t=s1->data;
	s1->data=s2->data;
	s2->data=t;
}
