#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node*preptr;
	struct node*nextptr;
}*head,*ennode;
void displaydl();
void createdl(int n);
int count();
int main()
{
	int n,c;
	head=NULL;
	ennode=NULL;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	createdl(n);
	displaydl();
	printf("\n");
	c=count();
	printf("no.of nodes:%d",c);
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
void displaydl()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("no data");
	}
	else
	{
		temp=head;
    	printf("data entered on the lists are:");
    	while(temp!=NULL)
	   {
		    printf("%d ",temp->num);
		    temp=temp->nextptr;
    	}
   }
}
int count()
{
	int c=0;
	struct node *temp;

		temp=head;
		while(temp!=NULL)
		{
			c++;
			temp=temp->nextptr;
	 	}
	 	return c;
}


