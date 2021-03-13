#include<stdio.h>
#include<stdlib.h>
struct arraystack
{
	int top;
	int capacity;
	int *array;	
};

struct arraystack *createstack(int);

struct arraystack *createstack(int cap)
{
	struct arraystack *stack;
	stack = (struct arraystack *)malloc(sizeof(struct arraystack));		//returns the void pointer that would be typecast into arraystack
	stack->top=-1;
	stack->capacity=cap;
	stack->array=malloc(sizeof(int)*stack->capacity);
	return(stack);
}

int isfull(struct arraystack *stack)
{
	if(stack->top==stack->capacity-1)
	return(1);
	else
	return(0);
}

int isempty(struct arraystack *stack)
{
	if(stack->top==-1)
	return(1);
	else
	return(0);
}

void push(struct arraystack *stack,int item)
{
	if(!isfull(stack))
	{
		stack->top++;
		stack->array[stack->top]=item;
	}
}

int pop(struct arraystack *stack)
{
	int item;
	if(!isempty(stack))
	{
		item=stack->array[stack->top];
		stack->top--;
		return(item);
	}
	return(-1);
}

int peek(struct arraystack *stack)
{
	if(stack->top==-1)
	return(-1);
	else
	return(stack->array[stack->top]);
}

void traverse(struct arraystack *stack)
{
	int i;
	if(stack->top==-1)
	printf("Stack is EMPTY\n");
	else
	printf("STACK elements are : \n");
	for(i=stack->top;i>=0;i--)
	{
		printf("%d\n",stack->array[i]);
	}
}

void main()
{
	int choice,item;
	struct arraystack *stack;
	stack=createstack(3);
	printf("\n\t\t\t 1. PUSH the item in the STACK\n");
	printf("\t\t\t 2. POP the item in the STACK\n");
	printf("\t\t\t 3. PEEK Value\n");
	printf("\t\t\t 4. TRAVERSE the STACK\n");
	printf("\t\t\t 5. EXIT\n");
	
	while(1)
	{
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(isfull(stack))
				printf("Stack is OVERFLOW");
				else
				{
					printf("Enter the value in STACK = ");
					scanf("%d",&item);
					push(stack,item);
				}
				break;
				
			case 2:
				item=pop(stack);
				if(item==-1)
				printf("Stack is EMPTY/UNDERFLOW");
				else
				printf("The Popped item is %d\n",item);
				
				break;
				
			case 3:
				item=peek(stack);
				if(item==-1)
				printf("Stack is EMPTY\n");
				else
				printf("PEEK value is %d",item);
				break;
				
			case 4:
				traverse(stack);
				break;
				
			case 5:
				exit(0);
				break;
			default:
				printf("Enter correct choice.");
		}
	}
}

