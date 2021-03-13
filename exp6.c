#include<stdio.h>
#include<time.h>
#define MAX 41
#define NIL -1

long int lookup[MAX];

void initialize()
{
	int i;
	for(i=0;i<MAX;i++)
	lookup[i]=NIL;
}

long int fib(long int n)
{
	if (lookup[n]==NIL)
	{
		if(n<=1)
		lookup[n]=n;
		else
		lookup[n]=fib(n-2)+fib(n-1);
	}
	return lookup[n];
}

void main()
{
	long int n;
	printf("Term of Fibonacci Series : ");
	scanf("%ld",&n);
	clock_t begin,end;
	double time_spent;
	initialize();
	begin = clock();
	printf("%ld \n",fib(n));
	end = clock();
	time_spent = (double)(end-begin)/CLK_TCK;
	printf("\n Time Taken : %lf",time_spent);
}
