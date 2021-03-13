#include<stdio.h>

int binary(int a[],int size,int element)
{
	int start=0;
	int end=size-1;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(a[mid]==element)
			return mid;
		else if(element<a[mid])
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}

void main()
{
	int n,value,pos,i,arr[10];
	printf("Enter the total elements in the array : ");
	scanf("%d",&n);
	
	printf("Enter elements in array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter element to search : ");
	scanf("%d",&value);
	
	pos=binary(arr,n,value);
	
	if(pos!=-1)
	{
		printf("Element found at %d\n",pos);
	}
	else
	{
		printf("Element not found.\n");
	}
}
