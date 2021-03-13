#include<stdio.h>

void hs(int a[],int n,int i)
{
	int j=1,left,right,max;
	max=i;
	left=2*j;
	right=2*j+1;
	if(left<n)
	{
		
	}	
}
void insert(int a[],int n)
{
	int t,i=n;
	t=a[n];
	while(i>1 && t>a[i/2])
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=t;
}

//void create()
//{
//	
//	int i;
//	for(i=2;i<=7;i++)
//	{
//		insert(a,i);
//	}
//}

void show(int arr[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d ",arr[i]);
	}
}

void main()
{
	int a[] = {0,40,35,30,15,10,25,5};
	int n=sizeof(a)/sizeof(int);
	hs(a,n,0);
	show(a,n);
//	insert(a,n);
}
