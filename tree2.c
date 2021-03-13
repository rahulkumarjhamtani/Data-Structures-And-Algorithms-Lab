#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
	int data; 
	struct node *left; 
	struct node *right; 
}; 


struct node* create() 
{
	int x; 
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	 
	printf("Data = ");
	scanf("%d",&x);
	if(x==-1)
		return 0;
	
	newnode->data = x;
	printf("Left child of %d\n",x);
	newnode->left=create();
	printf("Right child of %d\n",x);
	newnode->right=create(); 
	 
	return(newnode); 
} 

void preorder(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void main() 
{
	struct node *root;
	printf("Enter data -1 for no node\n");
	root=create();
	printf("\nPreorder traversal ->\n");
	preorder(root);  
} 

