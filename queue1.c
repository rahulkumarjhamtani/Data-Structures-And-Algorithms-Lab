#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int f;
	int r;
	int *arr;
};

int isfull(struct queue *q)
{
	if(q->r==q->size-1)
	return 1;
	return 0;
}

int isempty(struct queue *q)
{
	if(q->f==q->r)
	return 1;
	return 0;
}

void enqueue(struct queue *q,int val)
{
	if(isfull(q))
	{
		printf("Queue is Full\n");
	}
	else
	{
		q->r+=1;
		q->arr[q->r]=val;
		printf("Enqueue value : %d \n",val);
	}
}

int dequeue(struct queue *q)
{
	int a=-1;
	if(isempty(q))
	{
		printf("Queue is Empty\n");
	}
	else
	{
		q->f+=1;
		a=q->arr[q->f];
//		printf("Dequeue value : %d \n",a);
	}
	return a;
}

int main()
{
	struct queue q;
	q.size=5;
	q.f=q.r=-1;
	q.arr=(int *)malloc(q.size*sizeof(int));
	//Enqueue Operation
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,40);
	enqueue(&q,50);
	enqueue(&q,60);
	//Dequeue Operation
	printf("Deleted value : %d \n",dequeue(&q));
	printf("Deleted value : %d \n",dequeue(&q));
	printf("Deleted value : %d \n",dequeue(&q));
	printf("Deleted value : %d \n",dequeue(&q));
	printf("Deleted value : %d \n",dequeue(&q));
	enqueue(&q,80);
	printf("Deleted value : %d \n",dequeue(&q));
	
}
