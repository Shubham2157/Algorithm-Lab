#include <iostream>
#include <stdlib.h>

using namespace std;

void findSencondMaxMin(int *a, int n, int max_index, int min_index, bool called)
{
    int original_max_index = max_index;
    int original_min_index = min_index;

    max_index = 0;
    min_index = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > a[max_index] && a[i] != a[original_max_index])
            max_index = i;
        if (a[i] < a[min_index] && a[i] != a[original_min_index])
            min_index = i;
    }

    if (!called)
        findSencondMaxMin(a, n, max_index, min_index, true);
    else
        cout << "Second Max element is: " << a[max_index] << endl
             << "Second Min element is: " << a[min_index] << endl;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int max_range;
    cout << "Enter range of numbers to be present starting from 0 (positive): ";
    cin >> max_range;

    int a[n];
    for (int i = 0; i < n; ++i)
        a[i] = rand() % max_range;

    cout << "Generated array: " << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    findSencondMaxMin(a, n, 0, 0, false);

    return 0;
}
