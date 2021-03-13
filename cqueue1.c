#include<stdio.h>
#include<stdlib.h>

struct cqueue
{
	int size;
	int f,r;
	int *arr;
};

int isfull(struct cqueue *q)
{
	if((q->r+1)%q->size==q->f)
	return 1;
	return 0;
}

void enqueue(struct cqueue *q,int val)
{
	if(isfull(q))
	printf("Circular Queue is Full.\n");
	else
	{
		q->r=(q->r+1)%q->size;
		q->arr[q->r]=val;
		printf("Enqueue value : %d\n",val);
	}
}

int isempty(struct cqueue *q)
{
	if(q->f==q->r)
	return 1;
	return 0;
}

int dequeue(struct cqueue *q)
{
	int a=-1;
	if(isempty(q))
	printf("Circular Queue is Empty.\n");
	else
	{
		q->f=(q->f+1)%q->size;
		a=q->arr[q->f];
	}
	return a;
}

void main()
{
	struct cqueue q;
	q.size=4;
	q.f=q.r=0;
	q.arr=(int *)malloc(q.size*sizeof(int));
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,40);
	printf("Deleting value : %d \n",dequeue(&q));
	printf("Deleting value : %d \n",dequeue(&q));
	printf("Deleting value : %d \n",dequeue(&q));
	enqueue(&q,50);
	enqueue(&q,60);
	enqueue(&q,70);
	enqueue(&q,80);
	enqueue(&q,90);
	enqueue(&q,10);
	if(isempty(&q))
	{
		printf("Queue is Empty \n");
	}
	if(isfull(&q))
	{
		printf("Queue is Full \n");
	}
}
