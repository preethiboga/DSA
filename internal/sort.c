#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL;
void create(int n);
void display();
void sort();
void swap(struct node *a,struct node *b);
int main()
{
	int n;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	create(n);
	display();
	sort();
	display();
}
void create(int n)
{
	int i;
	struct node *nn,*temp;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&nn->data);
	nn->next=NULL;
	head=nn;
	temp=head;
	for(i=2;i<=n;i++)
	{
		nn=(struct node*)malloc(sizeof(struct node));
    	printf("enter data:");
    	scanf("%d",&nn->data);
	    nn->next=NULL;
	    temp->next=nn;
	    temp=nn;
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
void sort()
{
	int swapped;
	struct node *ptr1;
	struct node *lptr=NULL;
	if(head==NULL)
	{
		printf("no data");
		return;
	}
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
