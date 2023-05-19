#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 5
struct vertex{
	char label;
	bool visited;
};
int queue[MAX];
int rear=-1;
int front=0;
int queueitemcount=0;
struct vertex *lstvertices[MAX];
int adjmatrix[MAX][MAX];
int vertexcount=0;
void insert(int data)
{
	queue[++rear]=data;
	queueitemcount++;
}
int removedata()
{
	queueitemcount--;
	return queue[front++];
}
bool isqueueempty()
{
	return queueitemcount==0;
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
	printf("%c  ",lstvertices[vertexindex]->label);
}
int getadjunvisitedvertex(int vertexindex)
{
	int i;
	for(i=0;i<vertexcount;i++)
	{
		if(adjmatrix[vertexindex][i]==1 && lstvertices[i]->visited==false)
			return i;
	}
	return -1;
}
void breadthfirstsearch()
{
	int i;
	lstvertices[0]->visited=true;
	displayvertex(0);
	insert(0);
	int unvisitedvertex;
	while(!isqueueempty())
	{
		int tempvertex=removedata();
		while((unvisitedvertex=getadjunvisitedvertex(tempvertex))!=-1)
		{
			lstvertices[unvisitedvertex]->visited=true;
			displayvertex(unvisitedvertex);
			insert(unvisitedvertex);
		}
	}
	for(i=0;i<vertexcount;i++)
	{
		lstvertices[i]->visited=false;
	}
}
int main()
{
	int i,j,choice,n,e;
	char c,start,end;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		adjmatrix[i][j]=0;
	}
   /*	while(1)
	{
	printf("1.add vertex\n2.add edge\n3.bfs\n5.exit\n");
	printf("enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("enter no.of nodes:");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
		    	printf("enter vertex:");
			    scanf("%c",&c);
			    addvertex(c);
		    }
			break;
		case 2:
			printf("enter no.of edges:");
			scanf("%d",&e);
			for(i=0;i<e;i++)
			{
		        printf("enter start and end of edge:");
		        scanf("%c",&start);
		        scanf("%c",&end);
		        addedge(start,end);
		    }
		   break;
		case 3:
		   breadthfirstsearch();
		   break;  
		case 4:
		  exit(0);
		default:
		  printf("invalid\n");      	
	}
}*/
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
	breadthfirstsearch();
	return 0;
}

