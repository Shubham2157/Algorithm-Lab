#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *arr, size, capacity;

public:
    MaxHeap(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[c];
    }

    MaxHeap(int *a, int n)
    {
        capacity = n;
        size = n;
        arr = a;
    }

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void maxHeapify(int i);
    void buildHeap();
    void changeKey(int i, int x);
};

void MaxHeap::maxHeapify(int i)
{
    int lt = left(i), rt = right(i);
    int largest = i;

    if (lt < size && arr[largest] < arr[lt])
        largest = lt;
    if (rt < size && arr[largest] < arr[rt])
        largest = rt;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(largest);
    }
}

void MaxHeap::buildHeap()
{
    for (int i = (size - 2) / 2; i != 0; --i)
        maxHeapify(i);
}

void MaxHeap::changeKey(int i, int x)
{
    if (i >= size)
    {
        cout << "Wrong index provided!!\n";
        return;
    }

    int last_value = arr[i];
    arr[i] = x;

    if (x > last_value)
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    else
        maxHeapify(i);
}

int main()
{
    int a[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    MaxHeap A(a, n);

    A.buildHeap();
    A.changeKey(1, 2);

    cout << "Modified array: ";
    for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
    cout << endl;

    return 0;
}
