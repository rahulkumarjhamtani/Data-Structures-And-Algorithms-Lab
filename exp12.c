// C program for implementation of Bubble sort 
#include <stdio.h> 
  
void swap(int *a, int *b) 
{ 
    int temp;
	temp = *a; 
    *a = *b; 
    *b = temp; 
} 
   
void bubble(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  	{   
       for (j = 0; j < n-i-1; j++)  
           {
		   		if (arr[j] > arr[j+1]) 
              		{
              			swap(&arr[j], &arr[j+1]);
					}
        	}
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
	int n,i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in array -> \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	} 
//    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
//    int n = sizeof(arr)/sizeof(arr[0]); 
    bubble(arr, n); 
    printf("Sorted array: \n"); 
    print(arr, n); 
    return 0; 
} 
