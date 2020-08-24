#include <bits/stdc++.h>
using namespace std;

#define MAX 1000;
#define MILISECOND_CONVERSION 1000000

clock_t t_random, t_sorted, t_reverse;
bool ascending = false, descending = false;
bool array_generated = false;

void insertionSort(int *a, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void generateArray(int *a, int n)
{
    srand(time(0));
    for (int i = 0; i < n; ++i)
        a[i] = rand() % MAX;
}

void printArray(int a[], int n)
{
    cout << "Array:" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int menu(int *a, int n)
{
    cout << "********MENU********" << endl
         << "0. Quit" << endl
         << "1. Generate random array of n integers" << endl
         << "2. Display the array" << endl
         << "3. Sort Array in Ascending Order using Insertion Sort Algorithm" << endl
         << "4. Sort the Array in Descending Order by using any sorting algorithm" << endl
         << "5. Time Complexity to sort ascending of random data" << endl
         << "6. Time Complexity to sort ascending of data already sorted in ascending order" << endl
         << "7. Time Complexity to sort ascending of data already sorted in descending order" << endl
         << "8. Time Complexity to sort ascending of data for all Cases" << endl
         << endl;

    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl;

    clock_t t;

    switch (choice)
    {
    case 0:
        cout << "Program terminated!!" << endl;
        return 0;
        break;
    case 1:
        generateArray(a, n);
        cout << "Array generated!!" << endl;
        array_generated = true;
        break;
    case 2:
        if (array_generated)
            printArray(a, n);
        else
            cout << "Please generate the array first!!" << endl;
        break;
    case 3:
        t = clock();
        insertionSort(a, n);
        t = clock() - t;
        if (!ascending && !descending)
            t_random = t;
        else if (ascending)
            t_sorted = t;
        else
            t_reverse = t;
        cout << "Array sorted using Insertion Sort!!" << endl;
        ascending = true;
        descending = false;
        break;
    case 4:
        sort(a, a + n, greater<int>());
        ascending = false;
        descending = true;
        cout << "Array sorted in descending order!!" << endl;
        break;
    case 5:
        cout << "Time taken by Insertion Sort when an array of random numbers is passed is: " << double(t_random) * MILISECOND_CONVERSION / CLOCKS_PER_SEC << " miliseconds\n";
        break;
    case 6:
        cout << "Time taken by Insertion Sort when an array of already sorted numbers is passed is: " << double(t_sorted) * MILISECOND_CONVERSION / CLOCKS_PER_SEC << " miliseconds\n";
        break;
    case 7:
        cout << "Time taken by Insertion Sort when an array of reversely sorted numbers is passed is: " << double(t_reverse) * MILISECOND_CONVERSION / CLOCKS_PER_SEC << " miliseconds\n";
        break;
    case 8:
        cout << "Time taken by Insertion Sort when an array of random numbers is passed is: " << double(t_random) * MILISECOND_CONVERSION / CLOCKS_PER_SEC << " miliseconds\n";
        cout << "Time taken by Insertion Sort when an array of already sorted numbers is passed is: " << double(t_sorted) * MILISECOND_CONVERSION / CLOCKS_PER_SEC << " miliseconds\n";
        cout << "Time taken by Insertion Sort when an array of reversely sorted numbers is passed is: " << double(t_reverse) * MILISECOND_CONVERSION / CLOCKS_PER_SEC << " miliseconds\n";
        break;
    default:
        cout << "Wrong choice!!" << endl;
        break;
    }

    return 1;
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    cout << endl;

    int a[n], choice = 1;

    while (choice != 0)
    {
        choice = menu(a, n);
        cout << endl;
    }

    return 0;
}
