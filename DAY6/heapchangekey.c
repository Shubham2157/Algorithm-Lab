#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != i)
    {
        int t=arr[i];
        arr[i]=arr[largest];
        arr[largest]=t;

        heapify(arr, n, largest);
    }
}

void completeHeap(int arr[],int n){
   int i=0;
    for (i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);
}

void max_heap_changeKey(int arr[],int n, int i,int k){
    arr[i]=k;
    completeHeap(arr,n);
}


int main()
{
    int a[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
    int i;
    int n = sizeof(a)/sizeof(a[0]);
    completeHeap(a,n);
    printf("Original array :\n");
    for(i=0; i<n; ++i)
       printf("%d ",a[i]);
    max_heap_changeKey(a,n,2,2);
    printf("\n");
    printf("Array after change key operation :\n");
    for(i=0; i<n; ++i)
       printf("%d ",a[i]);
    printf("\n");


    return 0;
}
