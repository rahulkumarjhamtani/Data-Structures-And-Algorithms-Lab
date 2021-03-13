
// Heap Sort
#include<stdio.h>

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;	
} 
 

void maxheap(int arr[], int n, int i)
{
	int temp;
    int largest = i; 
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
		
//       		temp=arr[i];
//        	arr[i]=arr[largest];
//        	arr[largest]=temp;
		
 
        // Recursively heapify the affected sub-tree
        maxheap(arr, n, largest);
    }
}
 

void heapSort(int arr[], int n)
{
	int i,temp;

    for (i = n / 2 - 1; i >= 0; i--)
        maxheap(arr, n, i);
 

    for (i = n - 1; i > 0; i--) {
       
//       		temp=arr[0];
//        	arr[0]=arr[i];
//        	arr[i]=temp;
		 
        swap(&arr[0], &arr[i]);
 
      
        maxheap(arr, i, 0);
    }
}
 

int main()
{
	int i;
    int arr[] = {40,25,35,10,5,20,30,15};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
