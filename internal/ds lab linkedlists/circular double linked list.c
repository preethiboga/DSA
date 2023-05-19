#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *nextptr;
	struct node *preptr;
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
	struct node *temp,*nn;
	head=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	head->data=data;
	head->nextptr=NULL;
	head->preptr=NULL;
	temp=head;
	for(i=2;i<=n;i++)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
	    scanf("%d",&data);
	    nn->data=data;
	    nn->nextptr=NULL;
	    temp->nextptr=nn;
	    nn->preptr=temp;
	    temp=nn;
	}
	temp->nextptr=head;
	head->preptr=temp;	
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
			temp=temp->nextptr;
		}while(temp!=head);
	}
	printf("\n");	
}
void insert_begin()
{
	int data;
	struct node *nn,*temp;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	nn->data=data;
	nn->nextptr=head;
	temp=head;
	while(temp->nextptr!=head)
	{
		temp=temp->nextptr;
	}
	nn->preptr=temp;
	head=nn;
	temp->nextptr=head;
}
void insert_last()
{
	int data;
	struct node *nn,*curnode;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	nn->data=data;
	curnode=head;
	while(curnode->nextptr!=head)
	{
	    curnode=curnode->nextptr;
	}
	curnode->nextptr=nn;
	nn->preptr=curnode;
	nn->nextptr=head;
	head->preptr=nn;
}
void insert_pos()
{
	int data,pos,i;
	struct node *nn,*curnode,*prevnode;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&data);
	printf("enter pos:");
	scanf("%d",&pos);
	curnode=head;
	prevnode=head;
		for(i=2;i<=pos-1;i++)
		{
			curnode=curnode->nextptr;
		}
		nn->data=data;
		nn->preptr=curnode;
		nn->nextptr=curnode->nextptr;
		curnode->nextptr->preptr=nn;
		curnode->nextptr=nn;	
}
void del_begin()
{
	if(head==NULL)
	{
		printf("no elements\n");
	}
	else
	{
	struct node *temp;
	temp=head;
	temp->preptr->nextptr=temp->nextptr;
	head=head->nextptr;
	head->preptr=temp->preptr->nextptr;
	free(temp);
   }
}
void del_last()
{
	struct node *temp;
	temp=head;
	while(temp->nextptr!=head)
	{
		temp=temp->nextptr;
	}
	temp->preptr->nextptr=head;
	head->preptr=temp->preptr;
	free(temp);
}
void del_pos()
{
	struct node *prevnode,*curnode;
	prevnode=head;
	curnode=head;
	int pos,i;
	printf("enter position to delete:");
	scanf("%d",&pos);
	for(i=2;i<=pos;i++)
	{
		prevnode=curnode;
		curnode=curnode->nextptr;
	}
	prevnode->nextptr=curnode->nextptr;
	curnode->nextptr->preptr=prevnode;
	free(curnode);
	
}

