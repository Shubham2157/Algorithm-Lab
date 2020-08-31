#include <bits/stdc++.h>
using namespace std;

#define MAX 1000;
#define MICROSECOND_CONVERSION 1e6

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partition_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_r(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    int a[n];
    srand(time(0));
    for (int i = 0; i < n; ++i)
        a[i] = rand() % MAX;

    cout << "Generated array:\n";
    printArray(a, n);

    clock_t t;

    t = clock();
    quickSort(a, 0, n - 1);
    t = clock() - t;
    cout << "Time taken by Insertion Sort when an array of random numbers is passed is: " << double(t) * MICROSECOND_CONVERSION / CLOCKS_PER_SEC << " microseconds\n";

    t = clock();
    quickSort(a, 0, n - 1);
    t = clock() - t;
    cout << "Time taken by Insertion Sort when an array of already sorted numbers is passed is: " << double(t) * MICROSECOND_CONVERSION / CLOCKS_PER_SEC << " microseconds\n";

    sort(a, a + n, greater<int>());

    t = clock();
    quickSort(a, 0, n - 1);
    t = clock() - t;
    cout << "Time taken by Insertion Sort when an array of reversely sorted numbers is passed is: " << double(t) * MICROSECOND_CONVERSION / CLOCKS_PER_SEC << " microseconds\n";

    return 0;
}
