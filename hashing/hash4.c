#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10
int hashtable[TABLE_SIZE]={NULL};
void insert();
void display();
void search();
void del();
int main()
{
	int choice;
	while(1)
	{
		printf("1.insert\n2.search\n3.display\n4.delete\n5.exit\n");
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
	int data,h1key,index,h2key,i;
	printf("enter data to insert:");
	scanf("%d",&data);
	h1key=data%TABLE_SIZE;
	h2key=7-(data%7);
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(h1key+i*h2key)%TABLE_SIZE;
		if(hashtable[index]==NULL)
		{
			hashtable[index]=data;
			break;
		}
	}
	if(i==TABLE_SIZE)
	printf("not possible\n");	
}
void search()
{
	int key,h1key,h2key,i,index;
	printf("enter element to search:");
	scanf("%d",&key);
	h1key=key%TABLE_SIZE;
	h2key=7-(key%7);
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(h1key+i*h2key)%TABLE_SIZE;
		if(hashtable[index]==key)
		{
			printf("key found at index:%d\n",index);
			break;
		}
	}
	if(i==TABLE_SIZE)
	{
		printf("not found\n");
	}	
}
void display()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		printf("data:%d index:%d\n",hashtable[i],i);
	}
	printf("\n");
}
void del()
{
	int del,h1key,h2key,i,index;
	printf("enter data to del:");
	scanf("%d",&del);
	h1key=del%TABLE_SIZE;
	h2key=7-(del%7);
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(h1key+i*h2key)%TABLE_SIZE;
		if(hashtable[index]==del)
		{
			hashtable[index]=0;
			break;
		}	
	}
	if(i==TABLE_SIZE)
	{
		printf("not found\n");
	}
}
