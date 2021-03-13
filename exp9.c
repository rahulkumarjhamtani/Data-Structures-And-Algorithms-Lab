#include<stdio.h>

int linear(int arr[],int index,int n,int key)
{
	if(index>n)
	{
		return -1;
	}
	if(arr[index]==key)
	{
		return index;	
	}
	else
	{
		return linear(arr,index+1,n,key);
	}	
}

int main()
{
	int n,value,pos=0,i;
	printf("Enter the total elements in the array : ");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter elements in array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter element to search : ");
	scanf("%d",&value);

//	int arr[]={1,2,3,4,5};
//	value=1;
//	n=sizeof(arr)/sizeof(int);
	pos=linear(arr,0,n-1,value);
	
	if(pos!=-1)
	{
		printf("Element found at %d\n",pos);
	}
	else
	{
		printf("Element not found.\n");
	}
}
