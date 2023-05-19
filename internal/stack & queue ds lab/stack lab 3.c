# include<stdio.h>
# define MAX 5
int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void insert(int item)
{
	if(front==(rear+1)%MAX)
	{
		printf("Queue Overflow \n");
		return;
	}
	if (front == -1)  
	{
		front = 0;
		rear = 0;
	}
	else
	{
		rear=(rear+1)%MAX;
	}
	cqueue_arr[rear] = item ;
}

void del()
{
	if (front == -1)
	{
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted from queue is : %d\n",cqueue_arr[front]);
	if(front == rear) 
	{
		front = -1;
		rear=-1;
	}
	else
	{	
		front=(front+1)%MAX;
	}
}
void display()
{
	int i;
	for(i=front;i!=rear;i=(i+1)%MAX)
	{
		printf("%d ",cqueue_arr[i]);
	}
	printf("%d",cqueue_arr[rear]);
	printf("\n");
}

int main()
{
	int choice,item;
	do
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				printf("Input the element for insertion in queue : ");
				scanf("%d", &item);

				insert(item);
				break;
			case 2 :
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Wrong choice\n");
		}
	}while(choice!=4);
	
	return 0;
}
