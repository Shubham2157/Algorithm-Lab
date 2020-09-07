#include <bits/stdc++.h>
using namespace std;

class minHeap
{
    int *arr;
    int capacity;
    int size;

public:
    minHeap(int capacity, int size, const int *a)
    {
        this->capacity = capacity;
        this->size = size;
        arr = new int[capacity];

        for (int i = 0; i < size; ++i)
            arr[i] = a[i];
    }

    int left(int i) { return i * 2 + 1; }
    int right(int i) { return i * 2 + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void minHeapify(int i);
    void buildHeap();
    int extractMinimum();
    int findKthSmallest(int k);
};

void minHeap::minHeapify(int i)
{
    int smallest = i;
    int lt = left(i), rt = right(i);

    if (lt < size && arr[lt] < arr[smallest])
        smallest = lt;
    if (rt < size && arr[rt] < arr[smallest])
        smallest = rt;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(smallest);
    }
}

void minHeap::buildHeap()
{
    for (int i = (size - 2) / 2; i >= 0; --i)
        minHeapify(i);
}

int minHeap::extractMinimum()
{
    if (size == 0)
    {
        cout << "Cannot extract minimum!!\n";
        return -1;
    }

    int Min_element = arr[0];
    arr[0] = arr[size - 1];
    size--;

    minHeapify(0);

    return Min_element;
}

int minHeap::findKthSmallest(int k)
{
    for (int i = 1; i < k; ++i)
        extractMinimum();
    return extractMinimum();
}

class maxHeap
{
    int *arr;
    int capacity;
    int size;

public:
    maxHeap(int capacity, int size, const int *a)
    {
        this->capacity = capacity;
        this->size = size;
        arr = new int[capacity];

        for (int i = 0; i < size; ++i)
            arr[i] = a[i];
    }

    int left(int i) { return i * 2 + 1; }
    int right(int i) { return i * 2 + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void maxHeapify(int i);
    void buildHeap();
    int extractMaximum();
    int findKthLargest(int k);
};

void maxHeap::maxHeapify(int i)
{
    int largest = i;
    int lt = left(i), rt = right(i);

    if (lt < size && arr[lt] > arr[largest])
        largest = lt;
    if (rt < size && arr[rt] > arr[largest])
        largest = rt;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(largest);
    }
}

void maxHeap::buildHeap()
{
    for (int i = (size - 2) / 2; i >= 0; --i)
        maxHeapify(i);
}

int maxHeap::extractMaximum()
{
    if (size == 0)
    {
        cout << "Cannot extract maximum!!\n";
        return -1;
    }

    int Max_element = arr[0];
    arr[0] = arr[size - 1];
    size--;

    maxHeapify(0);

    return Max_element;
}

int maxHeap::findKthLargest(int k)
{
    for (int i = 1; i < k; ++i)
        extractMaximum();
    return extractMaximum();
}

int main()
{
    int capacity;
    cout << "Enter capacity of Heap: ";
    cin >> capacity;

    int size;
    while (size > capacity)
    {
        cout << "Enter current size of Heap (less than or equal to capacity): ";
        cin >> size;
    }

    int a[size];
    cout << "Enter elements in Heap:\n";
    for (int i = 0; i < size; ++i)
        cin >> a[i];

    minHeap min_h(capacity, size, a);
    min_h.buildHeap();

    int k;
    cout << "Enter k to find kth smallest element: ";
    cin >> k;

    cout << "kth smallest no. in Heap: " << min_h.findKthSmallest(k) << endl;

    maxHeap max_h(capacity, size, a);
    max_h.buildHeap();

    cout << "Enter k to find kth largest element: ";
    cin >> k;

    cout << "kth largest no. in Heap: " << max_h.findKthLargest(k) << endl;

    return 0;
}
