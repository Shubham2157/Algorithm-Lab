#include <bits/stdc++.h>
using namespace std;

pair<int, int> getMinMax(int a[], int low, int high)
{
    // first-MAX, second-MIN
    pair<int, int> min_max;

    if (low == high)
    {
        min_max.first = a[low];
        min_max.second = a[low];
        return min_max;
    }

    if (low == high + 1)
    {
        if (a[low] < a[high])
        {
            min_max.first = a[high];
            min_max.second = a[low];
        }
        else
        {
            min_max.first = a[low];
            min_max.second = a[high];
        }
        return min_max;
    }

    pair<int, int> min_max_l, min_max_r;
    int mid;

    mid = (low + high) / 2;
    min_max_l = getMinMax(a, low, mid);
    min_max_r = getMinMax(a, mid + 1, high);

    // Comparing MAX
    if (min_max_l.first < min_max_r.first)
        min_max.first = min_max_r.first;
    else
        min_max.first = min_max_l.first;

    // Comparing MIN
    if (min_max_l.second < min_max_r.second)
        min_max.second = min_max_l.second;
    else
        min_max.second = min_max_r.second;

    return min_max;
}

#define MAX 1000

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];
    srand(time(0));
    for (int i = 0; i < n; ++i)
        a[i] = rand() % MAX;
    cout << "\n";

    cout << "Generated array:\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n\n";

    pair<int, int> min_max = getMinMax(a, 0, n - 1);

    cout << "Max in array is: " << min_max.first << endl
         << "Min in array is: " << min_max.second << endl;

    return 0;
}
