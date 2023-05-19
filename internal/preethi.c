#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1;
int rear=-1;
int cq[MAX];
void enq();
void dq();
void display();
void enq()
{
	int data;
	printf("enter data:");
	scanf("%d",&data);
	if((front==0 && rear==MAX-1)|| front==rear+1)
	{
		printf("overflow\n");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		if(rear==MAX-1)
		rear=0;
		else
		rear=rear+1;
	}
	cq[rear]=data;
}
void dq()
{
	if(front==-1)
	{
		printf("empty\n");
		return;
	}
	printf("delted element is %d",cq[front]);
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		if(front==MAX-1)
		front=0;
		else
		front=front+1;
	}
}
void display()
{
	int f,r,i;
	f=front;
	r=rear;
	if(front==-1)
	{
		printf("empty\n");
		return;
	}
	else
	{
		if(f<=r)
		{
			for(i=f;i<=r;i++)
			{
				printf("%d ",cq[i]);
			}
		}
		else
		{
			for(i=0;i<MAX;i++)
			{
				printf("%d ",cq[i]);	
			}
			for(i=0;i<rear;i++)
			{
				printf("%d ",cq[i]);	
			}
		}
	}
	printf("\n");
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.enq\n2.deq\n3.display\n4.exit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enq();
				break;
			case 2:
			 dq();
			 break;
			 case 3:
			   display();
			   break;
			  case 4:
			    exit(0);
		     default:
			   printf("invalid choice");		 	
		}
	}
}
