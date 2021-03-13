#include<stdio.h>

void bucket(int a[],int n)
{
	int max, digits=0, pass, loc, div=1, i, j, k=0;
	int neb[10], buk[10][10];
	
	max=a[0];
	for(i=1;i<=n-1;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	while(max>0)
	{
		digits++;
		max=max/10;
	}
	for(pass=1;pass<=digits;pass++)
	{
		for(i=0;i<10;i++)
			neb[i]=0;
		for(i=0;i<n;i++)
		{
			loc=(a[i]/div)%10;
			buk[loc][neb[loc]++]=a[i];
		}
		for(i=0,k=0;i<10;i++)
		{
			for(j=0;j<neb[i];j++)
				a[k++]=buk[i][j];
		}
		div=div*10;
	}
}

void main()
{
	int arr[]={66,98,105,61,54,136};
	int i;
	int n=sizeof(arr)/sizeof(int);
	bucket(arr,n);
	
	for(i=0;i<=n-1;i++)
		printf("%d ",arr[i]);
}
