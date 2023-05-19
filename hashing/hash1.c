#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10
struct node{
	int data;
	struct node *next;
}*head[TABLE_SIZE]={NULL};
void insert();
void search();
void display();
void del();
int main()
{
	int choice;
	while(1)
	{
		printf("1.insert\n2.search\n3.display\n4.del\n5.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
			   search();
			   break;
			case 3:
			   display();
			   break;
			case 4:
			    del();
				break;
			case 5:
			    exit(0);
				break;	
			default:
			  printf("invalid choice\n");			     	
		}
	}
}
void insert()
{
	int data,i;
	struct node *nn,*t;
	printf("enter data:");
	scanf("%d",&data);
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	i=data%TABLE_SIZE;
	if(head[i]==NULL)
	{
		head[i]=nn;
	}
	else
	{
		t=head[i];
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=nn;
	}	
}
void search()
{
	struct node *t;
	int key,i,flag=0;
	printf("enter key to search:");
	scanf("%d",&key);
	i=key%TABLE_SIZE;
	if(head[i]==NULL)
	{
		flag=0;
	}
	else
	{
		t=head[i];
		while(t!=NULL)
		{
			if(t->data==key)
			{
				printf("key found at index:%d\n",i);
				flag=1;
				break;
			}
			t=t->next;
		}	
	}
	if(flag==0)
	{
		printf("not found\n");
	}
}
void display()
{
	struct node *t;
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		
		if(head[i]==NULL)
		continue;
			t=head[i];
			while(t!=NULL)
			{
				printf("data:%d index:%d\n",t->data,i);
				t=t->next;
			}	
	}
	printf("\n");
	
}
void del()
{
	int del,i,flag=0;;
	struct node *prev,*cur,*t,*temp;
	printf("enter data to del:");
	scanf("%d",&del);
	i=del%TABLE_SIZE;
	if(head[i]==NULL)
	{
		flag=0;
	}
	else
	{
		t=head[i];
		while(t!=NULL)
		{
			if(t->data==del)
			{
				flag=1;
				break;
			}
			t=t->next;
		}	
	}
	if(flag!=0)
	{
		cur=head[i];
		if(head[i]->data==del && head[i]->next==NULL)
		{
			free(head[i]);
		}
		else if(head[i]->data==del && head[i]->next!=NULL)
		{
			temp=head[i];
			head[i]=head[i]->next;
			free(temp);
		}
      else if(head[i]!=NULL)
      {
		while(cur->data!=del && cur!=NULL)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=cur->next;
		free(cur);
      }
  }
  else
  {
  	printf("not found\n");
  }	
}


