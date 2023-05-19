#include<stdio.h>
void quicksort(int a[],int first,int last,int n)
{
	int i,j,pivot,temp;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<last)
				i++;
			while(a[j]>a[pivot])
			    j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				
			}		
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
	    printarray(a,n);
		printf("\n");
		quicksort(a,0,j-1,n);
		quicksort(a,j+1,last,n);
	
	}	
}
int main()
{
	int n,i;
	printf("enter size of array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("before sorted:\n");
	printarray(a,n);
	quicksort(a,0,n-1,n);
	printf("after sorted:\n");
	printarray(a,n);
	
	return 0;
}
void printarray(int a[],int last)
{
	static int i=0;
	printf("array status after pass %d:",i);
	i++;
	int j;
	for(j=0;j<last;j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
}
