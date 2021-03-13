#include<stdio.h>

int power(int m,int n)
{
	if(n==0)
	return 1;
	if(n%2==0)
	return power(m*m,n/2);
	else
	return m*power(m*m,(n-1)/2);
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
