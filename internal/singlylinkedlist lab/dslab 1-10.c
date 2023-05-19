#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
}*head;
void createnode(int n);
void display();
void find(int element,int n);
int main()
{
	int n,place,element;
	printf("enter no.of elements:");
	scanf("%d",&n);
	createnode(n);
	printf("elements in list are:");
	display();
	printf("\n");
	printf("enter element to search:");
	scanf("%d",&element);
	find(element,n);
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
}
void find(int element,int n)
{
	struct node *temp;
	temp=head;
	int c=0,flag=0;
	while(temp!=NULL)
	{
		c++;
		  if(temp->data==element)
		  {
		  	printf("element found at :%d\n",c);
		  	flag=1;
		  	break;
		  }
		  temp=temp->next;
	}
   if(flag==0)
   {
   	printf("not found\n");
   }
}
