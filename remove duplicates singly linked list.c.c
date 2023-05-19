#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *next;
}*head=NULL;
struct node *createnode();
void removeduplicates();
void create(int n);
struct node *createnode()
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&nn->data);
	nn->next=NULL;
	return nn;
}
void create(int n)
{
	struct node *temp,*nn;
	head=createnode();
	temp=head;
	int i;
	for(i=2;i<=n;i++)
	{
		nn=createnode();
		temp->next=nn;
		temp=nn;
	}
}
void removeduplicates()
{
	struct node *current=head,*index=NULL,*temp=NULL;
	while(current!=NULL)
	{
		temp=current;
		index=current->next;
	    while(index!=NULL)
	    {
	    	if(current->data==index->data)
	    	{
	    		temp->next=index->next;
			}
			else
			{
				temp=index;
			}
			index=index->next;
		}
		current=current->next;
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
}
void sort()
{
	int swapped;
	struct node *ptr1,*lptr;
	lptr=NULL;
	if(head==NULL)
	return;
	do
	{
		swapped=0,ptr1=head;
		while(ptr1->next!=lptr)
		{
			if(ptr1->data>ptr1->next->data)
			{
				swap(ptr1,ptr1->next);
				swapped=1;
			}
			ptr1=ptr1->next;
		}
		lptr=ptr1;
	}while(swapped);
	
}
void swap(struct node *a,struct node *b)
{
	int t;
	t=a->data;
	a->data=b->data;
	b->data=t;
}
void main()
{
	int choice,n;
	while(1)
	{
		printf("1.create\n2.display\n3.remove\n4.sort\n5.exit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter no.of nodes:");
				scanf("%d",&n);
				create(n);
				break;
			case 2: 
			    display();
			    break;
			case 3:
			    removeduplicates();
			    break;
		    case 4:
			   sort();
			   break;
			case 5:
			   exit(0);   
			default:
			   printf("invalid choice");		   		  	    	
		}
	}
}
