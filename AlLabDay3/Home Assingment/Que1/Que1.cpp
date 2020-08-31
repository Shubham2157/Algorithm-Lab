#include <bits/stdc++.h>
using namespace std;

#define MAX 1000;

void insertionSort(int arr[], int n)
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
    insertionSort(a, n);
    t = clock() - t;
    cout << "Time taken by Insertion Sort when an array of random numbers is passed is: " << double(t) << " clock cycles\n";

    t = clock();
    insertionSort(a, n);
    t = clock() - t;
    cout << "Time taken by Insertion Sort when an array of already sorted numbers is passed is: " << double(t) << " clock cycles\n";

    sort(a, a + n, greater<int>());

    t = clock();
    insertionSort(a, n);
    t = clock() - t;
    cout << "Time taken by Insertion Sort when an array of reversely sorted numbers is passed is: " << double(t) << " clock cycles\n";

    return 0;
}
