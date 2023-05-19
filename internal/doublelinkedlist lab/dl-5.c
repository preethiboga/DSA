#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node*preptr;
	struct node*nextptr;
}*head,*ennode;
void display();
void delfirst();
void createdl(int n);
int main()
{
	int n;
	head=NULL;
	ennode=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	createdl(n);
	printf("before deletion:");
	printf("\n");
	display();
	printf("\n");
	delfirst();
	printf("after deletion:");
	printf("\n");
	display();
	return 0;
}
void createdl(int n)
{
	int i,num;
	struct node *fnnode;
	if(n>=1)
	{
		head=(struct node*)malloc(sizeof(struct node));
		if(head!=NULL)
		{
			printf("enter data:");
			scanf("%d",&num);
			head->num=num;
			head->preptr=NULL;
			head->nextptr=NULL;
			ennode=head;
			for(i=2;i<=n;i++)
			{
				fnnode=(struct node*)malloc(sizeof(struct node));
				if(fnnode!=NULL)
				{
					printf("enter data:");
					scanf("%d",&num);
					fnnode->num=num;
					fnnode->preptr=ennode;
					fnnode->nextptr=NULL;
					ennode->nextptr=fnnode;
					ennode=fnnode;
				}
			else
			{
				printf("memory can not be allocted");
				break;
			}
		  }
		}
	}
		else
		{
			printf("memory not allocted");
	   }
}

void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("no data");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->num);
			temp=temp->nextptr;
		}
	}
}
void delfirst()
{
	 struct node *nodetodel;
	 if(head==NULL)
	 {
	 	printf("deletion not possible");
	 }
	 else
	 {
	 	nodetodel=head;
	 	head=head->nextptr;
	 	head->preptr=NULL;
	 	free(nodetodel);
	 }
}
