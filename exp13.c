// C program for insertion sort  
#include <stdio.h> 
  
void insertion(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) 
	{ 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) 
		{ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void print(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
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
  
    insertion(arr, n);
	printf("Sorted Array : \n"); 
    print(arr, n); 
  
    return 0; 
} 
