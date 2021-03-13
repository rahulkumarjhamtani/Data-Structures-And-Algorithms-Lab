#include<stdio.h>
#include<time.h>

long int fib(long int n)
{
	long int f[41];
	long int i;
	f[0]=0;
	f[1]=1;
	for(i=2;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	return f[n];
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
