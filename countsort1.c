#include<stdio.h>

void countsort(int a[],int n)
{
	int max,i,j;
	max=findmax(a,n);
	int c[max+1];
	for(i=0;i<max+1;i++)
		c[i]=0;
	for(i=0;i<n;i++)
		c[a[i]]++;
	i=0;
	j=0;
	while(i<max+1)
	{
		if(c[i]>0)
		{
			a[j++]=i;
			c[i]--;
		}
		else
			i++;
	}
	
}

int findmax(int arr[],int n)
{
	int i,max;
	max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return(max);
}

void display(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
}

void main()
{
	int arr[6]={20,12,10,3,22,34};
	int n=6;
	int i;
//	printf("Enter number of elements in array - ");
//	scanf("%d",&n);
//	int arr[n];
//	printf("Enter elements in the array\n");
//	
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",&arr[i]);
//	}
	countsort(arr,n);
	display(arr,n);
}

