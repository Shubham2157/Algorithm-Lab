#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define MICROSECOND_CONVERSION 1000000

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
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout<<"Enter the no. of elements\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=rand()%100;

    clock_t t;
    t = clock();
    heapSort(arr, n);
    t = clock() - t;
    double time_taken = ((double)t)*MICROSECOND_CONVERSION/CLOCKS_PER_SEC; // in seconds
    cout << "Sorted array is \n";
    printArray(arr, n);
    cout<<"Time Taken :"<<time_taken<<" microseconds";
}
