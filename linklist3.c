#include<stdio.h>
#include<stdlib.h>

struct node
{						//structure of node
	int info;
	struct node *link;
};

int count=0;

struct node *START = NULL;    //start pointer to control the link list
struct node * createnode();
void insertnode();  //insert at last
void deletenode();	//delete at first
void viewlist();
int menu();
void insertatfirst();
int getlength();

struct node * createnode()			//create node dynamically
{
	struct node *n;
	n = malloc(sizeof(struct node));
	return(n);		
}
void insertnode()
{
	struct node *temp,*t;
	temp = createnode();
	printf("Enter the data in node \n");
	scanf("%d",&temp->info);
	temp->link=NULL;
	if(START==NULL)
	{
		START = temp;
	}
	else
	{
		t = START;
		while(t->link!=NULL)
		{
			t = t->link;
		}
		t->link=temp;
	}
}
void deletenode()
{
	if(START==NULL)
	printf("List is empty\n");
	else
	{
		struct node *q;
		q=START;
		START=START->link;
		free(q);
	}
}
void viewlist()
{
	struct node *t;
	if(START==NULL)
	printf("No List is there\n");
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

void insertatfirst()
{
	struct node *newnode;
	newnode=createnode();
	printf("Enter the data in node\n");
	scanf("%d",&newnode->info);
	if(START==NULL)
	START=newnode;
	else
	{
		newnode->link=START;
		START=newnode;	
	}	
}


int getlength()
{
	struct node *t;
	if(t==NULL)
	printf("List is EMPTY\n");
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
	int ch;
	printf("\t\t\t 1. Insert NODE at last in LINK LIST\n");
	printf("\t\t\t 2. View LIST in LINK LIST\n");
	printf("\t\t\t 3. Delete NODE at first in LINK LIST\n");
	printf("\t\t\t 4. Insert NODE at first in LINK LIST\n");
	printf("\t\t\t 5. To see the length\n");
	printf("\t\t\t 6. Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	return(ch);
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
				viewlist();
				break;
			case 3:
				deletenode();
				break;
			case 4:
				insertatfirst();
				break;
			case 5:
				k=getlength();
				printf("The length of link list is %d",k);
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nThis choice doesn't exist.\n");
		}
	}
}







