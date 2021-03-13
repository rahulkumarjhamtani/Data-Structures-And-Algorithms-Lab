#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *LAST = NULL;
struct node *createnode();
struct node *insertatfirst(struct node *LAST,int value);
struct node *insertatempty(struct node *LAST,int value);
struct node *insertatend(struct node *LAST,int value);
struct node *insertafter(struct node *LAST,int value,int item);
struct node *createlist(struct node *LAST);
void display(struct node *LAST);
int menu();

struct node *createnode()
{
	struct node *n;
	n=malloc(sizeof(struct node));
	return(n);
}

struct node *insertatfirst(struct node *LAST,int value)
{
	struct node *n;
	n = createnode();
	
	n->data=value;
	n->next=LAST->next;
	LAST->next=n;
	
	return(LAST);
}

struct node *insertatempty(struct node *LAST,int value)
{
	struct node *n;
	n=createnode();
	n->data=value;
	
	LAST=n;
	LAST->next=LAST;
	
	return(LAST);
}

struct node *insertatend(struct node *LAST,int value)
{
	struct node *n;
	n=createnode();
	n->data=value;
	
	if(LAST==NULL)
	printf("List is Empty\n");
	
	else
	{
		n->next=LAST->next;
		LAST->next=n;
		LAST=n;
	}
	return(LAST);
}

struct node *insertafter(struct node *LAST,int value,int item)
{
	struct node *t,*n;
	t=LAST->next;
	
	do
	{
		if(t->data==item)
		{
			n=createnode();
			n->data=value;
			
			n->next=t->next;
			t->next=n;
			
			return(LAST);
		}
		t=t->next;
	}while(t!=LAST->next);
printf("%d is not present in the LIST",item);
return(LAST);
}

struct node *createlist(struct node *LAST)
{
	int n,value,i;
	printf("Number of values : ");
	scanf("%d",&n);
	printf("Enter first data\n");
	scanf("%d",&value);
	LAST=insertatempty(LAST,value);
	
	for(i=2;i<=n;i++)
	{
		printf("Enter remaining data\n");
		scanf("%d",&value);
		LAST=insertatend(LAST,value);
	}
	return(LAST);
}

void display(struct node *LAST) 	//to access the link list using LAST traverse value
{
	struct node *t;
	if(LAST==NULL)
	printf("List is Empty\n");
	else
	{
		t=LAST->next;
		do
		{
			printf("%d ",t->data);
			t=t->next;
		}
		while(t!=LAST->next);
	}
	
}

int menu()
{
	int ch;
	printf("\n\t\t\t 1. Create LIST in LINK LIST\n");
	printf("\t\t\t 2. View LIST in LINK LIST\n");
	printf("\t\t\t 3. Insert NODE at first in LINK LIST\n");
	printf("\t\t\t 4. Insert NODE at empty NODE in LINK LIST\n");
	printf("\t\t\t 5. Insert NODE at Last in LINK LIST\n");
	printf("\t\t\t 6. Insert After a Node in LINK LIST\n");
	printf("\t\t\t 7. Exit\n");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	return(ch);
}

void main()
{
	struct node *LAST=NULL;
	int item,value;
	while(1)
	{
		switch(menu())
		{
			case 1:
				LAST = createlist(LAST);
				break;
			case 2:
				display(LAST);
				break;
			case 3:
				printf("Enter the value : ");
				scanf("%d",&value);
				LAST = insertatfirst(LAST,value);
				break;
			case 4:
				printf("Enter the value : ");
				scanf("%d",&value);
				LAST = insertatempty(LAST,value);
				break;
			case 5:
				printf("Enter the value : ");
				scanf("%d",&value);
				LAST = insertatend(LAST,value);
				break;
			case 6:
				printf("Enter the value after which you want to insert node : ");
				scanf("%d",&item);
				printf("Enter the value : ");
				scanf("%d",&value);
				LAST = insertafter(LAST,value,item);
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("\nThis choice doesn't exist.\n");
				break;
		}
	}
}
