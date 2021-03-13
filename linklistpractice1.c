#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

int count=0;

struct node *START=NULL;
struct node *createnode();
void insertnode();
void deletenode();
void view();
void insertatfirst();
void deleteatlast();
int menu();
int getlength();


struct node *createnode()
{
	struct node *n;
	n=malloc(sizeof(struct node));
	return(n);
}

void insertnode()
{
	struct node *temp,*t;
	temp=createnode();
	printf("Enter the data : ");
	scanf("%d",&temp->info);
	temp->link=NULL;
	if(START==NULL)
	START=temp;
	else
	{
		t=START; 
		while(t->link!=NULL)
		{
			t=t->link;
		}	
		t->link=temp;
	}
}

void view()
{
	struct node *t;
	if(START==NULL)
	printf("\nList is Empty\n");
	else
	{
		t=START;
		while(t!=NULL)
		{
			printf("%d",t->info);
			t=t->link;
		}
	}
}

void deletenode()
{
	if(START==NULL)
	printf("\nList is Empty\n");
	else
	{
		struct node *q;
		q=START;
		START=START->link;
		free(q);
	}
}

void insertatfirst()
{
	struct node *newnode;
	newnode=createnode();
	printf("Enter the data : ");
	scanf("%d",&newnode->info);
	if(START==NULL)
	START=newnode;
	else
	{
		newnode->link=START;
		START=newnode;
	}
	
}

void deleteatlast()
{
	struct node *q;
	struct node *t;
	if(START==NULL)
	printf("\nList is Empty\n");
	else
	{
		q=START;
		t=START;
		while(t->link!=NULL)
		{
			q=t;
			t=t->link;
		}
		if(t==START)
		{
			START=NULL;
		}
		else
		{
			q->link=NULL;
			free(t);
		}
	}
}

int getlength()
{
	struct node *t;
	if(t==NULL)
	printf("/nList is Empty\n");
	else
	{
		t=START;
		while(t!=NULL)
		{
			count+=1;
			t=t->link;
		}
		return(count);
	}
}

int menu()
{
	int m;
	printf("\n1. Insert a node in LINK LIST\n");
	printf("\n2. View node in LINK LIST\n");
	printf("\n3. Delete node in LINK LIST\n");
	printf("\n4. Insert node at first in LINK LIST\n");
	printf("\n5. Delete node at last in LINK LIST\n");
	printf("\n6. Number of nodes in LINK LIST\n");
	printf("\n7. Exit\n");
	printf("\nEnter your choice : ");
	scanf("%d",&m);
	return(m);
}

int main()
{
	int k;	
	while(1)
	{
		switch(menu())
		{
		case 1:
		insertnode();
		break;	
		case 2:
		view();
		break;
		case 3:
		deletenode();
		break;
		case 4:
		insertatfirst();
		break;
		case 5:
		deleteatlast();
		break;
		case 6:
		k=getlength();
		printf("Number of nodes : %d\n",k);
		break;
		case 7:
		exit(0);
		break;
		default:
			printf("\nThis choice does not exist\n");
		}
	}	
}
