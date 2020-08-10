#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int x = a;
    a = b;
    b = x;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << "Original array:" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    // Swapping pairs
    for (int i = 0; i < n; i += 2)
    {
        if (i == n - 1)
            break;
        swap(a[i], a[i + 1]);
    }

    cout << "Modified array:" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
