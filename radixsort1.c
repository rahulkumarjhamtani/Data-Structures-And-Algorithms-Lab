#include<stdio.h>

void radixsort(int a[],int n)
{
	int i,k;
//	int max=findmax(a,n);
	int bin[n];
	for(i=0;i<n;i++)
		k=a[i]%10;
		bin[k]=a[i];
	for(i=0;i<n;i++)
		k=a[i/10]%10;
		bin[k]=a[i];
	for(i=0;i<n;i++)
		k=a[i/100]%100;
		bin[k]=a[i];
	for (i = 0; i < n; i++)
		a[i]=bin[i]; 
        printf("%d ", a[i]);
	
}


void main()
{
	int arr[10]={237,146,259,348,152,162,235,48,36,62};
	int n=10;
//	int n,i;
//	printf("Enter number of elements in array - ");
//	scanf("%d",&n);
//	int arr[n];
//	printf("Enter elements in the array\n");
//	
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",&arr[i]);
//	}
	radixsort(arr,n);

}

