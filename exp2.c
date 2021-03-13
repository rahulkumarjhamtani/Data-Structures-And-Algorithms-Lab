#include<stdio.h>

int factorial(int n)
{
	if(n==0)
	return 1;
	else 
	return factorial(n-1)*n;
}

void main()
{
	int num,a;
	printf("Number : ");
	scanf("%d",&num);
	a= factorial(num);
	printf("Factorial = %d",a);
}
