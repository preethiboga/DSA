#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
struct vertex{
	char label;
	bool visited;
};
struct vertex *lstvertices[MAX];
int vertexcount=0;
int stack[MAX];
int top=-1;
int adjmatrix[MAX][MAX];
void push(int item)
{
	stack[++top]=item;
}
int pop()
{
	return stack[top--];
}
bool isstackempty()
{
	return top==-1;
}
void addvertex(char label)
{
	struct vertex *vertex=(struct vertex*)malloc(sizeof(struct vertex));
	vertex->label=label;
	vertex->visited=false;
	lstvertices[vertexcount++]=vertex;
}
void addedge(int start,int end)
{
	adjmatrix[start][end]=1;
	adjmatrix[end][start]=1;
}
void displayvertex(int vertexindex)
{
	printf("%c ",lstvertices[vertexindex]->label);
}
int getadjunvisitedvertex(int vertexindex)
{
	int i;
	for(i=0;i<vertexcount;i++)
	{
		if(adjmatrix[vertexindex][i]==1 && lstvertices[i]->visited==false)
		{
			return i;
		}
	}
	return -1;
}
void depthfirstsearch()
{
	int i;
	lstvertices[0]->visited=true;
	displayvertex(0);
	push(0);
	while(!isstackempty())
	{
		int unvisitedvertex=getadjunvisitedvertex(peek());
		if(unvisitedvertex==-1){
		pop();
	     }
		else
		{
			lstvertices[unvisitedvertex]->visited=true;
			displayvertex(unvisitedvertex);
			push(unvisitedvertex);
		}
	}
	for(i=0;i<vertexcount;i++)
	{
		lstvertices[i]->visited=false;
	}
}
int peek()
{
	return stack[top];
}
int main()
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			adjmatrix[i][j]=0;
		}
	}
	addvertex('s');
	addvertex('a');
	addvertex('b');
	addvertex('c');
	addvertex('d');
	addedge(0,1);
	addedge(0,2);
	addedge(0,3);
	addedge(1,4);
	addedge(2,4);
	addedge(3,4);
	depthfirstsearch();
	return 0;
}
