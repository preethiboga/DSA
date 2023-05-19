#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 10
int stack[MAX];
char postfix[20];
int top=-1;
void push(int c)
{
	if(top==MAX-1)
	printf("overflow\n");
	else
	{
		top=top+1;
		stack[top]=c;
	}
}
int pop()
{
	int c;
	if(top==-1)
	printf("underflow\n");
	else
	{
		c=stack[top];
		top--;
	}
	return c;
}
int evaluate()
{
	int res,i,a,b;
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
					res=a+b;
					break;
				case '-':
					res=b-a;
					break;
				case '*':
					res=a*b;
					break;
				case '/':
				   res=b/a;
				   break;
				case '^':
				   res=pow(b,a);
				   break;   			
			}
			push(res);	
		}
	}
	return pop();
	
}
void display()
{
	int j=0;
	while(postfix[j])
	{
		printf("%c",postfix[j++]);
	}
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}

void main()
{
	printf("enter postfix:");
	gets(postfix);
   int res=evaluate();
	printf("%d",res);
}

