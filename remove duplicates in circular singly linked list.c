#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head;
void swap(struct node *a,struct node *b);
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
	temp->next=head;
}
void display()
{
	struct node *temp;
	if(head==NULL)
	printf("empty\n");
	else
	{
		temp=head;
		do{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
}
void sort()
{
	struct node *ptr1=head,*lptr=head;
	int swapped=0;
	if(head==NULL)
	printf("empty");
	else
	{
		do{
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
}
void swap(struct node *a,struct node *b)
{
	int t;
	t=a->data;
	a->data=b->data;
	b->data=t;	
}
void removeduplicates()
{
	struct node *current=head,*temp=NULL,*index=NULL;
	do{
		temp=current;
		index=current->next;
		do{
			if(current->data==index->data)
			{
				temp->next=index->next;
			}
			else
			{
				temp=index;
			}
			index=index->next;
		}while(index!=head);
		current=current->next;	
	}while(current!=head);
}
void main()
{
	int choice,n;
	while(1)
	{
		printf("1.create\n2.display\n3.sort\n4.remove\n5.exit\n");
		printf("enter your choice:");
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
		       sort();
			   break;
			case 4:
			   removeduplicates();
			   break;
			case 5:
			   exit(0);
			default:
			  printf("invalid choice");         			
		}
		
	}
}
