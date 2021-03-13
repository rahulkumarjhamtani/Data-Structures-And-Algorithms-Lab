#include<stdio.h>

int fibonacci(int n)
{
	if(n<=1)
	return n;
	else
	return fibonacci(n-2)+fibonacci(n-1);
}

void main()
{
	int num,a;
	printf("Term of fibonacci series : ");
	scanf("%d",&num);
	a=fibonacci(num);
	printf("Number = %d",a);
}
