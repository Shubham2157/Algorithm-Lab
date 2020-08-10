#include <iostream>
using namespace std;

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

    int product = 1, last_val = a[0];
    a[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        product *= last_val;
        last_val = a[i];
        a[i] = product;
    }

    cout << "Modified array:" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
