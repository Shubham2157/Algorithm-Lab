#include <bits/stdc++.h>
using namespace std;

void printProductArray(int a[], int n, int product)
{
    for (int i = 0; i < n; ++i)
        cout << product / a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {10, 4, 1, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int product = 1;
    for (int i = 0; i < n; ++i)
        product *= a[i];

    cout << "Original array:\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    cout << "array after operation:\n";
    printProductArray(a, n, product);

    return 0;
}
