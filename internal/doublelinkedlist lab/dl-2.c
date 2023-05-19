#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *preptr;
	struct node *nextptr;
}*head,*ennode;
void createdl(int n);
void display();
void insertbegin(int num1);
int main()
{
	int n,num1;
	head=NULL;
	ennode=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	createdl(n);
	printf("before inserting:");
	display();
	printf("\n");
	printf("enter number to insert at begining:");
	scanf("%d",&num1);
	insertbegin(num1);
	printf("after inserting:");
	display();
	return 0;
}
void createdl(int n)
{
	int num,i;
	struct node *fnnode;
	if(n>=1)
	{
		head=(struct node*)malloc(sizeof(struct node));
		if(head!=NULL)
		{
			printf("enter data:");
			scanf("%d",&num);
			head->num=num;
			head->preptr=NULL;
			head->nextptr=NULL;
			ennode=head;
			for(i=2;i<=n;i++)
			{
				fnnode=(struct node*)malloc(sizeof(struct node));
				if(fnnode!=NULL)
				{
					printf("enter data:");
					scanf("%d",&num);
					fnnode->num=num;
					fnnode->preptr=ennode;
					fnnode->nextptr=NULL;
					ennode->nextptr=fnnode;
					ennode=fnnode;
				}
				else
				{
					printf("memory not allocted:");
					break;
				}
			}
		}
	}
		else
		{
			printf("memory not allocted");
		}
}
void insertbegin(int num1)
{
	struct node *newnode;
	if(head==NULL)
	{
		printf("no data found");
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->num=num1;
		newnode->preptr=NULL;
		newnode->nextptr=head;
		head->preptr=newnode;
		head=newnode;
	}
}
void display()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("no data found");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->num);
			temp=temp->nextptr;
		}
	}
}

