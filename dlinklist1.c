#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev,*next;
};

struct node *START=NULL;

void insertatfirst();
void view();
void deleteatfirst();
int menu();

void insertatfirst()
{
	struct node *newnode;
	newnode = malloc(sizeof(struct node));
	printf("\nEnter the data\n");
	scanf("%d",&newnode->info);
	newnode->prev=NULL;
	newnode->next=NULL;
	
	if(START==NULL)
	START=newnode;
	
	else
	{
		START->prev=newnode;
		newnode->next=START;
		START=newnode;
	}
}

void deleteatfirst()
{
	struct node *temp;
	if(START==NULL)
	printf("\nList is Empty\n");
	
	else
	{
		temp = START;
		START = START->next;
		START->prev = NULL;
		free(temp);
	}
}

void view()
{
	struct node *s;
	if(START==NULL)
	printf("\nList is Empty\n");
	
	else
	{
		s = START;
		while(s!=NULL)
		{
			printf("%d ",s->info);
			s = s->next;
		}
	}	
}

int menu()
{
	int ch;
	printf("\n1. Insert NODE at first in LINK LIST\n");
	printf("\n2. View LIST in LINK LIST\n");
	printf("\n3. Delete NODE at first in LINK LIST\n");
	printf("\n4. Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	return(ch);
}
 
int main()
{
	while(1)
	{
		switch(menu())
		{
			case 1:
				insertatfirst();
				break;
			case 2:
				view();
				break;
			case 3:
				deleteatfirst();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nThis choice doesn't exist.\n");
		}
	}
}
