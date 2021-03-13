#include<stdio.h>

void qs(int arr[],int p,int r)
{
	if(p<r)
	{
		int q;
		q=partition(arr,p,r);
		qs(arr,p,q-1);
		qs(arr,q+1,r);
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int p,int r)
{
	int x,j,i;
	x=arr[r];
	i=p-1;
	 for (j = p; j <= r- 1; j++) 
    { 
        if (arr[j] < x) 
        { 
            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[r]); 
    return (i + 1); 
}
  
int main() 
{ 
    int n,arr[n],i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	printf("Enter elements in array -> \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}  
    qs(arr, 0, n-1); 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
