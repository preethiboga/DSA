#include<stdio.h>
void insertionsort(int a[],int size);
main()
{
	int n,i;
	printf("enter size of an array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter elements in the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("unsorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);
	}
	insertionsort(arr,n);
	printarray(arr,n);
	
}
void insertionsort(int a[],int size)
{
	int i,j,temp;
	for(i=1;i<=size;i++)
	{
		temp=a[i];
		for(j=i;j>0&&a[j-1]>temp;j--)
		{
			a[j]=a[j-1];
		}
		a[j]=temp;
		printf("\n");
		printf("array status after pass %d:\n",i-1);
		printarray(a,size);
		
	}
}
void printarray(int a[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
}
