#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head;
void creation(int n);
void display();
void insert_begin();
void insert_last();
void insert_pos();
void del_begin();
void del_last();
void del_pos();
int main()
{
	while(1)
	{
		int choice,n;
		printf("1.create\n2.insert end\n3.insert begin\n4.insert pos\n5.del last\n6.del begin\n7.del pos\n8.display\n9.quit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter no.of nodes:");
				scanf("%d",&n);
				creation(n);
				break;
			case 2:
			     insert_last();
				 break;
			case 3:
			     insert_begin();
				 break;
			case 4:
			     insert_pos();
				 break;
			case 5:
			     del_last();
				 break;	 
		    case 6:
			    del_begin();
				break;
			case 7:
			    del_pos();
				break;
			case 8:
			    display();
				break;
			case 9:
			   exit(0);
			default:
			  printf("invalid choice\n"); 					 	 	 	
		}
	}
	return 0;
}
void creation(int n)
{
	int data,i;
	struct node *newnode,*temp;
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
	temp->next=head;
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("no data");
	}
	else
	{
		temp=head;
		do
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
	printf("\n");
}
void insert_begin()
{
	int data;
	struct node *newnode,*curnode;
	printf("enter data to insert:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=head;
	curnode=head;
	while(curnode->next!=head)
	{
		curnode=curnode->next;
	}
	head=newnode;
	curnode->next=head;
}
void insert_last()
{
	int data;
	struct node *newnode,*curnode;
	printf("enter data to insert:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	curnode=head;
	while(curnode->next!=head)
	{
		curnode=curnode->next;
	}
	curnode->next=newnode;
	newnode->next=head;
}
void insert_pos()
{
	int data,i,pos;
	struct node *newnode,*curnode;
	printf("enter data to insert:");
	scanf("%d",&data);
	printf("enter pos:");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("no data\n");
	
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
    	newnode->data=data;
    	curnode=head;
    	for(i=2;i<=pos-1;i++)
    	{
    		curnode=curnode->next;
		}
		newnode->next=curnode->next;
		curnode->next=newnode;
	}
}
void del_begin()
{
	struct node *temp,*curnode;
	curnode=head;
	while(curnode->next!=head)
	{
		
		curnode=curnode->next;
	}
	temp=head;
	head=head->next;
	curnode->next=head;
	free(temp);
}
void del_last()
{
	struct node *prevnode,*nodetodel;
	nodetodel=head;
	prevnode=head;
	while(nodetodel->next!=head)
	{
		prevnode=nodetodel;
		nodetodel=nodetodel->next;
	}
	prevnode->next=head;
	free(nodetodel);
}
void del_pos()
{
	int pos,i;
	printf("enter pos to delete:");
	scanf("%d",&pos);
	struct node *prevnode,*curnode;
	prevnode=head;
	curnode=head;
	if(head==NULL)
	{
		printf("not possible\n");
	}
	else
	{
		for(i=2;i<=pos;i++)
		{
			prevnode=curnode;
			curnode=curnode->next;
		}
		prevnode->next=curnode->next;
		free(curnode);
	}
	
	
}


