#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;
void insert();
void del();
void display();
int main()
{
	int choice;
	while(1)
	{
		printf("1.insert\n 2.delete\n 3.display\n 4.exit\n");
    	printf("enter your choice:");
    	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
			    exit(0);
				break;
			case 5:
				printf("invalid choice\n");
				break;   	
		}
	}
}
void insert()
{
	int value;
	printf("enter data to insert:");
	scanf("%d",&value);
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void display()
{
	if(front==NULL)
	{
		printf("queue is empty");
	}
	else
	{
		struct node *temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void del()
{
	if(front == NULL)
	{
		printf("queue is empty");
	}
	else
	{
		struct node *temp=front;
		front=front->next;
		printf("deleted element:%d\n",temp->data);
		free(temp);
	}
}
