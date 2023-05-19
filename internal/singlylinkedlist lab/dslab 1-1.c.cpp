#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
}*head;
void createnode(int n);
void display();
void reverse(struct node *head);
void sort(struct node *head);
void swap(struct node *a,struct node *b);
int main()
{
	int n;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("elements in list are:");
	display();
     reverse(head);
     display();
	return 0;
}
void createnode(int n)
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
	printf("\n");
	
}
void reverse(struct node *head)
{
	if(head==NULL)
	return;
		reverse(head->next);
		printf("%d ",head->data);
	
}
void sort(struct node *head)
{
	int swapped=0;
	struct node *lptr,*ptr1;
	lptr=NULL;
	ptr1=head;
	if(head==NULL)
	{
		printf("empty\n");
	}
	
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
void swap(struct node *a,struct node *b)
{
	int t;
	t=a->data;
	a->data=b->data;
	b->data=t;
}
