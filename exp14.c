// C program for implementation of selection sort 
#include <stdio.h> 

void swap(int *a, int *b) 
{ 
	int temp;
	temp = *a; 
	*a = *b; 
	*b = temp; 
} 

void selection(int arr[], int n) 
{ 
	int i, j, k; 

	for (i = 0; i < n-1; i++) 
	{ 
		k = i; 
		for (j = i+1; j < n; j++) 
		{
			if (arr[j] < arr[k]) 
				k = j; 
		}
		swap(&arr[k], &arr[i]); 
	} 
} 


void print(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
 
int main() 
{ 
	int n,arr[n],i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	printf("Enter elements in array -> \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	} 
	selection(arr, n); 
	printf("Sorted array: \n"); 
	print(arr, n); 
	return 0; 
} 

