#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
}*head=NULL;
void display();
void insert_begin();
void insert_end();
void insert_mid();
void del_begin();
void del_end();
void del_mid();
void create();
int main()
{
	int choice;
	while(1)
	{
		printf("0.create\n1.display\n2.insert begin\n3.insert end\n4.insert middle\n5.delete begin\n6.delete end\n7.delete middle\n8.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				create();
				break;
			case 1:
				display();
				break;
			case 2:
			    insert_begin();
				break;
			case 3:
			    insert_end();
				break;
			case 4:
			    insert_mid();
				break;
			case 5:
			   del_begin();
			   break;
			case 6:
			   del_end();
			   break;
			case 7:
				del_mid();
				break;
			case 8:
			   exit(0);
			   break;
			default:
			    printf("invalid choice\n");	     				
		}
	}
}
void create()
{
	int n,data,i;
	printf("enter no.of elements:");
	scanf("%d",&n);
	struct node *temp,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	head=newnode;
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
	    scanf("%d",&data);
    	newnode->data=data;
    	newnode->prev=temp;
    	temp->next=newnode;
    	newnode->next=NULL;
    	temp=newnode;
	}
	
}
void insert_end()
{
	int data;
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data=data;
    if(head==NULL)
	{
		newnode->prev=NULL;
	    newnode->next=NULL;
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
		newnode->next=NULL;
		
	}
}
void insert_begin()
{
	int data;
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data=data;
	if(head==NULL)
	{
		newnode->prev=NULL;
	    newnode->next=NULL;
		head=newnode;
	}
	else
	{
		newnode->prev=NULL;
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		
	}
}
void insert_mid()
{
	int data,pos,i;
	struct node *newnode,*temp;
	temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	printf("enter position:");
	scanf("%d",&pos);
	for(i=2;i<=pos-1;i++)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			break;
		}
	}
	if(temp!=NULL)
	{
		newnode->data=data;
		newnode->next=temp->next;
		newnode->prev=temp;
		temp->next->prev=newnode;	
		temp->next=newnode;
		
	}
}
void del_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("underflow\n");
	}
		else if(head->next==NULL)
		{
			head=NULL;
			free(head);
		}
		else
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
			
		}
}
void del_end()
{

	struct node *nodetodel,*prevnode;
	if(head==NULL)
	{
		printf("underflow\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
	}
	else
	{
		nodetodel=head;
		prevnode=head;
		while(nodetodel->next!=NULL)
		{
			prevnode=nodetodel;
			nodetodel=nodetodel->next;
		}
		prevnode->next=NULL;
		nodetodel->prev=NULL;
		free(nodetodel);
	}
}
void del_mid()
{
	int pos,i;
	struct node *nodetodel,*prevnode;
	nodetodel=head;
	prevnode=head;
	printf("enter location:");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("underflow\n");
	}
	for(i=2;i<=pos;i++)
	{
		prevnode=nodetodel;
		nodetodel=nodetodel->next;
		if(nodetodel==NULL)
		{
			break;
		}
	}
	if(nodetodel!=NULL)
	{
		if(nodetodel==head)
		{
			head=head->next;
		}
		else
        {
	   prevnode->next=nodetodel->next;
	   nodetodel->next->prev=prevnode;
	   nodetodel->next=NULL;
	   free(nodetodel);
      }     
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
