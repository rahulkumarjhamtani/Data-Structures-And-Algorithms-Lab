#include<stdio.h>
#include<time.h>

long int fib(long int n)
{
	if (n<=1)
	return n;
	else
	return fib(n-2)+fib(n-1);
}

void main()
{
	long int n;
	printf("Term of Fibonacci Series : ");
	scanf("%ld",&n);
	clock_t begin,end;
	double time_spent;
	begin = clock();
	printf("%ld \n",fib(n));
	end = clock();
	time_spent = (double)(end-begin)/CLK_TCK;
	printf("\n Time Taken : %lf",time_spent);
}
