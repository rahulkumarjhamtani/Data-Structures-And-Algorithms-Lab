#include<stdio.h>

int rbs(int a[10],int l,int h,int key)
{
	int mid;
	if(l<=h)
	{
		mid = (l+h)/2;
		if(a[mid]==key)
		return mid;
		if(a[mid]<key)
		return rbs(a,mid+1,h,key);
		else
		return rbs(a,l,mid-1,key);
	}
	return -1;
}

void main()
{
	int arr[10],n,i,key,index;
	printf("Enter the numbers you want to insert : ");
	scanf("%d",&n);
	printf("Numbers want to insert\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Number you want to search : ");
	scanf("%d",&key);
	
	index=rbs(arr,0,n-1,key);
	if(index!=-1)
	printf("Number is at %d position",index);
	else
	printf("Number not found.");
}
