#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX],infix[MAX],postfix[MAX];
int top=-1;
void push(char c);
char pop();
void print();
int priority(char symbol);
int isempty();
void infix_postfix();
int space(char c);
void push(char c)
{
	if(top==MAX-1)
	{
		printf("overrflow\n");
		return;
	}
	top++;
	stack[top]=c;
}
char pop()
{
	char c;
	if(top==-1)
	{
		printf("underflow\n");
		return;
	}
	c=stack[top];
	top=top-1;
	return c;
}
void print()
{
	int j=0;
	while(postfix[j])
	{
		printf("%c",postfix[j++]);
	}
	printf("\n");
}
int space(char c)
{
	if(c==' '||c=='\t')
	return 1;
	else
	return 0;
}
int priority(char symbol)
{
	switch(symbol)
	{
		case '*':
	    case '/':		
			return 2;
		case '+':
		case '-':
		    return 1;
	    case '^':
		    return 3;
		default:
		  return 0;				
	}
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void infix_postfix()
{
	int i,j=0;
	char next,symbol;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(!space(symbol))
		{
			switch(symbol)
			{
				case '(':
					push(symbol);
					break;
				case ')':
				    while((next=pop())!='(')
					postfix[j++]=next;
					break;
				case '+':
				case '-':
				case '*':
				case '/':
				    while(!isempty() && priority(stack[top])>=priority(symbol))
					    postfix[j++]=pop();
					push(symbol);
					break;
				default:
				  postfix[j++]=symbol;			
			}
		}	
	}
	while(!isempty())
	postfix[j++]=pop();
	postfix[j]='\0';
}
int main()
{
	printf("enter infix:");
	gets(infix);
	infix_postfix();
	print();
	return 0;
	
}

