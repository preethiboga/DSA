#include<stdio.h>
#define max 10
int front=-1,rear=-1;
void del();
void display();
void insert();
int queue[max];
int main()
{
	int choice;
	while(1)
	{
		printf("1.Insert element to queue\n");
		printf("2.Delete element from queue\n");
		printf("3.Display all elements of queue\n");
		printf("4.Exit\n");
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
			default:
			    printf("invalid choice\n");		 	
		}
	}	
}
void insert()
{
	int data;
	if(rear==max-1)
	{
    	printf("queue overflow\n");
    	return;
    }
	else
	{
		if(front==-1)
		{
			front=0;
		}
	    printf("enter data to insert:");
	    scanf("%d",&data);
	    rear=rear+1;
	    queue[rear]=data;
    }	
}
void del()
{
	if(front==-1||front>rear)
	{
		printf("queue underflow\n");
		return;
	}
	else
	{
		printf("element deleted from queue is:%d\n",queue[front]);
		front=front+1;
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}
