#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL;
void display();
void insert_begin();
void insert_end();
void insert_pos();
void del_end();
void del_begin();
void del_pos();
void create();
void create ()
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
	head=newnode;
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
	    printf("enter data:");
	    scanf("%d",&data);
	    newnode->data=data;
	    temp->next=newnode;
    	newnode->next=NULL;
    	temp=newnode;
	}
}
void insert_end()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	
}
void insert_begin()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void insert_pos()
{
	int data,pos,i;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	printf("enter position to insert:");
	scanf("%d",&pos);
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head->next=NULL;
		head=newnode;
	}
	else
	{
		struct node *temp;
		temp=head;
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
				newnode->next=temp->next;
				temp->next=newnode;
			}
		
	}	
}
void del_end()
{
	struct node *nodetodel,*prevnode;
	nodetodel=head;
	prevnode=head;
	while(nodetodel->next!=NULL)
	{
		prevnode=nodetodel;
		nodetodel=nodetodel->next;
	}
	prevnode->next=NULL;
	free(nodetodel);
}
void del_begin()
{
	if(head==NULL)
	{
		printf("no elements");
	}
	else
	{
	struct node *nodetodel;
	nodetodel=head;
	head=head->next;
	free(nodetodel);
   }
}
void del_pos()
{
	int pos,i;
	struct node *nodetodel,*prevnode;
	printf("enter positon to delete:");
	scanf("%d",&pos);
	nodetodel=head;
	prevnode=head;
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
void main()
{
	int choice;
	while(1)
	{
		printf("0.create\n1.insert end\n2.insert begin\n3.insert middle\n4.delbegin\n5.delend\n6.delmiddle\n7.display\n8.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				create();
				break;
			case 1:
				insert_end();
				break;
			case 2:
			     insert_begin();
			     break;
			case 3:
			    insert_pos();
			    break;
			case 4:
				del_begin();
				break;
			case 5:
			    del_end();
			    break;
			case 6:
			     del_pos();
			     break;
			case 7:
			     display();
			     break;
			case 8:
			     exit(0);
			     break;
			default:
			     printf("invalid choice\n");       	     
				
		}
	}
	
}


