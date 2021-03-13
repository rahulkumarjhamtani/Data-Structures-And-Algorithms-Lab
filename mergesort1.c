#include<stdio.h>

void ms(int arr[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		ms(arr,p,q);
		ms(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

int merge(int a[],int p,int q,int r)
{
	int i=p;
	int j=q+1;
	int k=p;
	int b[r+1];
	while(i<=q && j<=r)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=q)
		b[k++]=a[i++];
	while(j<=r)
		b[k++]=a[j++];
	for(i=p;i<=r;i++)
	{
		a[i]=b[i];
	}
}

void main()
{
	int i;
	int arr[]={2,5,8,12,3,6,7,10};
	int n=sizeof(arr)/sizeof(int);
	ms(arr,0,n-1);
	for(i=0;i<=n-1;i++)
	{
		printf("%d ",arr[i]);
	}
}
