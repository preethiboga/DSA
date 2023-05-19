#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 10
struct vertex{
	char label;
	bool visited;
};
void addvertex(char label);
void display(int vertexindex);
int top=-1;
int adjmatrix[MAX][MAX];
int vertexcount=0;
int stack[MAX];
struct vertex *lstvertices[MAX];
void addvertex(char label)
{
	struct vertex *vertex;
	vertex=(struct vertex*)malloc(sizeof(struct vertex));
	vertex->label=label;
	vertex->visited=false;
	lstvertices[vertexcount++]=vertex;
}
void addedge(int start,int end)
{
	adjmatrix[start][end]=1;
	adjmatrix[end][start]=1;
}
void push(int item)
{
	stack[++top]=item;
}
int pop()
{
	return (stack[top--]);
}
bool isempty()
{
	return top==-1;
}
int getadjunvisited(int vertexindex)
{
	int i;
	for(i=0;i<vertexcount;i++)
	{
		if(adjmatrix[vertexindex][i]==1 && lstvertices[i]->visited==false)
		return i;
	}
	return -1;
}
void bfs()
{
	lstvertices[0]->visited=true;
	push(0);
	display(0);
	int unvisitedvertex;
	while(!isempty())
	{
		unvisitedvertex=getadjunvisited(peek());
		if(unvisitedvertex==-1)
		pop();
		else
		{
			lstvertices[unvisitedvertex]->visited=true;
			display(unvisitedvertex);
		    push(unvisitedvertex);
		}	
	}	
}
int peek()
{
	return stack[top];
}
void display(int vertexindex)
{
	printf("%c ",lstvertices[vertexindex]->label);
}
void main()
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		adjmatrix[i][j]=0;
	}
	int choice,start,end,n,e;
	char v;
	while(1)
	{
		printf("1.addvertex\n2.addedge\n3.bfs\n4.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter no.of vertices:");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("enter vertex:");
					scanf("%c",v);
					addvertex(v);
				}
				break;
			case 2:
			   printf("enter no.of edges:");
			   scanf("%d",&e);
			   for(j=0;j<e;j++)
			   {
			   	  printf("enter start:");
			   	  scanf("%d",&start);
			   	  printf("enter end:");
			   	  scanf("%d",&end);
			   	  addedge(start,end);
				}
				break;
			case 3:
			  bfs();
			  break;
			case 4: 
			   exit(0);
			default:
			   printf("invalid choice");     		
		}
		
	}
}
