#include<stdio.h>

int binary(int a[],int start,int end,int element)
{
	if(start>end)
		return -1;
	
	int mid=(start+end)/2;
	if(a[mid]==element)
		return mid;
	else if(element<a[mid])
		binary(a,start,mid-1,element);
	else
		binary(a,mid+1,end,element);
	
//	return -1;
}

void main()
{
	int n,value,pos,i,arr[10];
	
	printf("Enter the total elements in the array : ");
	scanf("%d",&n);
	
	int start=0;
	int end=n-1;
	
	printf("Enter elements in array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter element to search : ");
	scanf("%d",&value);
	
	pos=binary(arr,start,end,value);
	
	if(pos!=-1)
	{
		printf("Element found at %d\n",pos);
	}
	else
	{
		printf("Element not found.\n");
	}
}
