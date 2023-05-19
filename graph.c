#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void read_graph(struct node *adj[],int nodes);
void print_graph(struct node *adj[],int nodes);
void main()
{
	int nodes,i;
	printf("enter no.of nodes:");
	scanf("%d",&nodes);
	struct node *adj[nodes];
	for(i=0;i<nodes;i++)
		adj[i]=NULL;
	read_graph(adj,nodes);
	print_graph(adj,nodes);	
	
}
void print_graph(struct node *adj[],int nodes)
{
	int i;
	struct node *t;
	for(i=0;i<nodes;i++)
	{
		printf("\nThe neighbours of %d are:",i+1);
		t=adj[i];
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;	
		}
	}
}
void read_graph(struct node *adj[],int nodes)
{
	int i,j,data,k;
	struct node *nn;
	for(i=0;i<nodes;i++)
	{
		struct node *last=NULL;
		printf("enter the no.of neighbours of %d node:",i+1);
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			printf("enter the value of %d neighbour of %d:",j+1,i+1);
			scanf("%d",&data);
			nn=(struct node*)malloc(sizeof(struct node));
			nn->next=NULL;
			nn->data=data;	
			if(adj[i]==NULL)
		    adj[i]=nn;
		    else
		    last->next=nn;
		    last=nn;
		}
	}
}
