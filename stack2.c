#include<stdio.h>
#include<stdlib.h>

struct linkliststack
{
    int data;
    struct linkliststack *next;
};
struct linkliststack *top = NULL;

struct linkliststack **start = &top;

// Declaration of function
struct linkliststack *createnode();
void push();
void pop();
void peek();
void display();

// creating stack node
struct linkliststack *createnode()
{
    struct linkliststack *newnode;
    newnode = (struct linkliststack *)malloc(sizeof(struct linkliststack));
    newnode->next = NULL;
    return newnode;
}

//push data into stack
void push()
{
    struct linkliststack *newnode;
    newnode = createnode();
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    if( newnode == NULL )
    {
        printf("\nStack Overflow");
    }
    if ((*start) == NULL)
    {
        (*start) = newnode;
    }
    else
    {
        newnode->next = (*start);
        (*start) = newnode;
    }

}

//pop data from stack
void pop()
{
    if ((*start) == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        struct linkliststack *temp;
        temp = (*start);
        printf("\nPopped value is %d\n",temp->data);
        (*start) = (*start)->next;
        free(temp);
    }

}

//Peek function
void peek()
{
    if((*start) == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        printf("\nPeek value is %d\n",(*start)->data);
    }

    
}

//Display Stack

void display()
{
    struct linkliststack *temp;
    if ((*start) == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        temp = (*start);
        printf("\nElements in the stack:  ");
        while (temp != NULL)
        {
            printf("\n %d ", temp->data);
            temp = temp->next;
        }
        
    }

}

void menu()
{
    printf("\nSTACK using LINK LIST \n");
    printf("1. PUSH value in STACK\n");
    printf("2. POP value in STACK\n");
    printf("3. PEEK value\n");
    printf("4. TRAVERSE the STACK\n");
    printf("5. EXIT\n");

}

void main()
{
    int ch;
    menu();
    while (1)
    {
        printf("\nEnter your choice - ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input\n");
                break;
        }
    }
    
}
