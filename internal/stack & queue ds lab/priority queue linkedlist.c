#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int priority;
	struct node *next;
};
struct node *front=NULL;
struct node *createnode();
void enqueue();
void dequeue();
int main()
{
	int choice;
	while(1)
	{
		printf("1.enqueue\n2.dequeue\n3.display\n4.quit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
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
	return;
	
}
struct node *createnode()
{
	int data,p;
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d", &data);
	nn->data=data;
	printf("enter priority:");
	scanf("%d",&p);
	nn->priority=p;
	nn->next=NULL;
	return nn;
}
void enqueue()
{
	struct node *nn,*temp=front;
	nn=createnode();
	if(front==NULL||nn->priority<front->priority)
	{
		nn->next=front;
		front=nn;
	}
	else
	{
		while(temp->next!=NULL && temp->next->priority<=nn->priority)
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
	
}
void dequeue()
{
	struct node *temp=front;
	if(front==NULL)
	printf("empty\n");
	else
	{
		front=front->next;
		free(temp);
	}
}
void display()
{
	struct node *temp=front;
	if(front==NULL)
	{
	    printf("empty\n");
	    return;
    }
	while(temp!=NULL)
	{
		printf("data->%d  priority->%d\n",temp->data,temp->priority);
		temp=temp->next;
	}
	printf("\n");
}

