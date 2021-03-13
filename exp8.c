#include<stdio.h>

void TOH(int n,char a,char b,char c)
{
	if(n>0)
	{
		TOH(n-1,a,c,b);
		printf("(%c,%c)\n",a,c);
		TOH(n-1,b,a,c);
	}
}

void main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	TOH(n,'A','B','C');
}
