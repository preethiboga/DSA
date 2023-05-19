#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void display();
void createnode(int n);
void delmid(int pos);
int main()
{
	int n,data,pos;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("before deletion:");
	display();
	printf("\n");
	printf("enter position to delete:");
	scanf("%d",&pos);
	delmid(pos);
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
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void delmid(int pos)
{
	struct node *todelmid,*prevnode;
	int i;
	if(head==NULL)
	{
		printf("no elements");
	}
	else
	{
		todelmid=head;
	    prevnode=head;
	    for(i=2;i<=pos;i++)
	    {
	    	prevnode=todelmid;
	    	todelmid=todelmid->next;
	    	if(todelmid==NULL)
	    	{
	    		break;
			}
		}
		if(todelmid!=NULL)
		{
			if(todelmid==head)
			{
				head=head->next;
			}
			prevnode->next=todelmid->next;
			todelmid->next=NULL;
			free(todelmid);
		}
		else
		{
			printf("deletion can't possible");
		}
	}
	
}


