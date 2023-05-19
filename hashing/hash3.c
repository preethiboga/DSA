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
	int data,hkey,index,i;
	printf("enter data:");
	scanf("%d",&data);
	hkey=data%TABLE_SIZE;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(hkey+(i*i))%TABLE_SIZE;
		if(hashtable[index]==NULL)
		{
			hashtable[index]=data;
			break;
		}
	}
	if(i==TABLE_SIZE)
	{
		printf("not possible\n");
	}
	
}
void display()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		printf("%d ",hashtable[i]);
	}
	printf("\n");
}
void search()
{
	int key,hkey,index,i;
	printf("enter key to search:");
	scanf("%d",&key);
	hkey=key%TABLE_SIZE;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(hkey+(i*i))%TABLE_SIZE;
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
void del()
{
	int del,hkey,i,index;
	printf("enter data to del:");
	scanf("%d",&del);
	hkey=del%TABLE_SIZE;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(hkey+(i*i))%TABLE_SIZE;
		if(hashtable[index]==del)
		{
			hashtable[index]=NULL;
			break;
		}
	}
	if(i==TABLE_SIZE)
	{
		printf("not found\n");
	}
}
