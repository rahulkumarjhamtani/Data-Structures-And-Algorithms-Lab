#include<stdio.h>
#include<stdlib.h>
#define N 5		//macro

int stack1[N],stack2[N];
int top1=-1,top2=-1;

void enqueue(int);
void dequeue();
void push1(int);
int pop1();
void push2(int);
int pop2();
void display();
int count=0;

void enqueue(int val)
{
	push1(val);
	count++;
}

void push1(int val)
{
	if(top1==N-1)
	{
		printf("Queue is Full\n");
	}
	else
	{
		top1++;
		stack1[top1]=val;
	}
}

void push2(int val)
{
		top2++;
		stack2[top2]=val;
}

int pop1()
{
	return stack1[top1--];
}

int pop2()
{
	return stack2[top2--];
}

void dequeue()
{
	if(top1==-1&&top2==-1)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		int i,b;
		for(i=0;i<count;i++)
		{
			push2(pop1());
		}
		b=pop2();
		count--;
		for(i=0;i<count;i++)
		{
			push1(pop2());
		}
	}
}

void display()
{
	int i;
	for(i=0;i<=top1;i++)
	{
		printf("%d\n",stack1[i]);
	}
}

void main()
{
	dequeue();		//queue is empty
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();
	enqueue(60);	//queue is full
	
	dequeue();
	display();		//20 30 40 50

}
