#include<stdio.h>
#define MAX 100
int n,choice,x,top,i,stack[MAX];
void push();
void pop();
void display();
int main()
{
	top=-1;
	printf("enter size of array:");
	scanf("%d",&n);
	while(1)
	{
     	printf("1.push\n2.pop\n3.display\n4.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					push();
					break;
				}
		    case 2:
			    {
			    	pop();
			    	break;
				} 
			case 3:
			    {
			    	display();
			    	break;
				}
			case 4:
				{
					printf("exit");
					break;
				}
			default:
			    {
			    	printf("enter valid choice");	
				}	
		}
	}

	return 0;	
}
void push()
{
	if(top>=n-1)
	{
		printf("stack overflow\n");
	}
	else
	{
		printf("enter value to be pushed:");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("stackunderflow\n");
	}
	else
	{
		printf("the popped element is %d\n",stack[top]);
		top--;
	}
}
void display()
{
	if(top>=0)
	{
		for(i=top;i>=0;i--)
		{
			printf("%d ",stack[i]);
		}
		printf("\n");
	}
	else
	{
		printf("stack is empty");
	}
}

