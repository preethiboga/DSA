#include<stdio.h>
void heapify(int a[],int n,int i);
void heapsort(int a[],int n);
void printarray(int a[],int n);
void swap(int *a,int *b);
int main()
{
	int n,i;
	printf("enter no.of elements:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("enter element %d:",i);
		scanf("%d",&a[i]);
	}
	printf("unsorted array is:");
	printarray(a,n);
	heapsort(a,n);
	printf("sorted array:");
	printarray(a,n);
	
}
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void heapsort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	heapify(a,n,i);
	for(i=n-1;i>=0;i--)
	{
	   swap(&a[0],&a[i]);
	    heapify(a,i,0);
    }
}
void heapify(int a[],int n,int i)
{
	int max=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[max])
	max=l;
	if(r<n && a[r]>a[max])
	max=r;
	if(max!=i)
	{
		swap(&a[i],&a[max]);
		heapify(a,n,max);
	}
}
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
