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
void insertatfirst();	//insert at first
void insertafterposition();		//insert after any position
int getlength();
void deleteatlast();

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


void deleteatlast()
{
	struct node *q;
	struct node *t;
	if(START==NULL)
	printf("List is empty\n");
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
		else{
		q->link=NULL;
		free(t);
		}
		
		
		
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

void insertafterposition()
{
	int position;
	struct node *newnode,*t;
	if(START==NULL)
	printf("List is empty\n");
	else
	{
		printf("Enter the position of node after which you want to insert node\n");
		scanf("%d",&position);
		if(position>getlength())
		{
			printf("Enter correct position\n");
			insertafterposition();
		}
		else
		{
			int i=1;
			newnode=createnode();
			printf("Enter data\n");
			scanf("%d",&newnode->info);
			newnode->link=NULL;
			if(START==NULL)
			START=newnode;
			else
			{
				t=START;
				while(i<position)
				{
					t=t->link;
					i++;
				}
				newnode->link=t->link;
				t->link=newnode;
			}
		}
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
	printf("\t\t\t 6. Insert after a node in LINK LIST\n");
	printf("\t\t\t 7. Delete last node in LINK LIST\n");
	printf("\t\t\t 8. Exit\n");
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
				insertafterposition();
				break;
			case 7:
				deleteatlast();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("\nThis choice doesn't exist.\n");
		}
	}
}







