#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void push(int);
void pop();
void display();
int main()
{
	int choice,value;
	while(1)
	{
		printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("enter value to be pushed:");
					scanf("%d",&value);
					push(value);
					break;	
			case 2:
					pop();
					break;
			case 3:
			    	display();
			    	break;
			case 4:
			    	exit(0);
			    	break;
			default:
					printf("invalid choice");	
		}
	}
}
void push(int value)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	if(top==NULL)
	{
		newnode->next=NULL;
	}
	else
	{
		newnode->next=top;
	}
	top=newnode;
}
void pop()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		struct node *temp=top;
		printf("popped element:%d\n",temp->data);
		top=top->next;
		free(temp);
	}
}
void display()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		struct node *temp=top;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
