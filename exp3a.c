#include<stdio.h>

int power(int m,int n)
{
	if(n==0)
	return 1;
	else 
	return power(m,n-1)*m;
}

void main()
{
	int a,b,c;
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	c=power(a,b);
	printf("%d ^ %d = %d",a,b,c);
	
}
