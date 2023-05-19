#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void display();
void createnode(int n);
void sort();
void swap(struct node *a,struct node *b);
int main()
{
	int n;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("before reversing:");
	display();
	printf("\n");
	sort();
	display();
}
void createnode(int n)
{
	struct node *newnode,*temp;
	int data,i;
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
		temp=temp->next;
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
			printf("%d " ,temp->data);
			temp=temp->next;
		}
	}
}
void reverse(struct node *h)
{
    if(h==NULL)
    return;
    else
    {
    	reverse(h->next);
    	printf("%d ",h->data);
    	
	}
}
void sort()
{
	struct node *ptr1,*lptr;
	lptr=NULL;
	int swapped;
	do{
			ptr1=head;
			swapped=0;
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

