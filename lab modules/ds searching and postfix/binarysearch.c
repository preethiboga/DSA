#include<stdio.h>
void main()
{
	int a;
	printf("enter size of array:");
	scanf("%d",&a);
	int arr[a],i,key,first,last,middle;
	for(i=0;i<a;i++)
	{
		printf("enter %d element:",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<a;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("enter key:");
	scanf("%d",&key);
	first=0;
	last=a-1;
	middle=(first+last)/2;
	while(first<=last)
	{
		if(arr[middle]<key)
		  first=middle+1;
		else if(arr[middle]==key)
			{
			    printf("key found at index %d ",middle);
		       break;
		    }
     	else
		     last=middle-1;
	      middle=(first+last)/2;
    }
	if(first>last)
	 printf("not found");

}
