#include<stdio.h>
int selectionsort(int a[],int size);
int max(int a[],int size);
main()
{
	int i,n;
	printf("enter size of an array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("unsorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
	selectionsort(arr,n);
	
}
void printarray(int a[],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d ",a[i]);
}
int max(int a[],int size)
{
	int max=0,i;
	for(i=1;i<=size;i++)
	{
		if(a[i]>a[max])
		{
			max=i;
		}
    }
    return(max);
}
int selectionsort(int a[],int size)
{
	int temp,big,i;
	for(i=size-1;i>=0;i--)
	{
		big=max(a,i);
		temp=a[i];
		a[i]=a[big];
		a[big]=temp;
		printf("\n");
		printf("array status after  pass %d:",size-i-1);
		printarray(a,size);
	}
	return;
}
