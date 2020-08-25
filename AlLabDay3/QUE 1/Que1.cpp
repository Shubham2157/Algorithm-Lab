#include <bits/stdc++.h>
using namespace std;

#define MAX 1000;
#define MICROSECOND_CONVERSION 1e6

int binarySearch(int a[], int n, int target, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (a[mid] == target)
        return mid;
    else if (a[mid] < target)
        return binarySearch(a, n, target, mid + 1, end);
    else
        return binarySearch(a, n, target, start, mid - 1);
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

    sort(a, a + n);

    cout << "Generated array:\n";
    printArray(a, n);

    int index, target;
    cout << "Enter a no. to search in array: ";
    cin >> target;

    clock_t t;

    t = clock();
    index = binarySearch(a, n, target, 0, n - 1);
    if (index == -1)
        cout << "Target not found in array!!" << endl;
    else
        cout << target << " found at position " << index << endl;
    t = clock() - t;
    cout << "Time taken by Binary Search is: " << double(t) * MICROSECOND_CONVERSION / CLOCKS_PER_SEC << " microseconds\n";

    return 0;
}
