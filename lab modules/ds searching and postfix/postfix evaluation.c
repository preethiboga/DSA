#include<stdio.h>
#include<ctype.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int element)
{
	if(top==MAX-1)
	{
		printf("stack is full\n");
		return;
	}
	else
	{
		top=top+1;
		stack[top]=element;
	}
}
int pop()
{
	if(top==-1)
	{
		printf("stack is underflow\n");
		return;
	}
	else
	{
		return stack[top--];
	}
}
int evaluate(char postfix[])
{
	int a,b ,result;
	int i;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
		{
			push(postfix[i]-'0');
		}
		else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+':
					result=a+b;
					break;
				case '-':
					result=b-a;
					break;
				case '*':
					result=a*b;
					break;
				case '/':
					result=b/a;
					break;		
			}
			push(result);
	    }
	}
	return pop();	
}
int main()
{
	char postfix[MAX];
	int res;
	printf("enter postfix expression:");
	scanf("%s",postfix);
	res=evaluate(postfix);
	printf("result:%d",res);
	return 0;
}
