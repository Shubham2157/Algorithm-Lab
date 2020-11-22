#include <bits/stdc++.h>

using namespace std;

bool findSum(int arr[], int n, int x)
{
    unordered_set<int> s;

    for (int i = 0; i < n; ++i)
    {
        if (s.find(x - arr[i]) != s.end())
            return true;
        s.insert(arr[i]);
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int x;
    cout << "Enter x: ";
    cin >> x;

    bool found = findSum(arr, n, x);

    if (found)
        cout << "We have a pair of elements in array whose sum equals to x!!\n";
    else
        cout << "We don't have a pair of elements in array whose sum equals to x!!\n";

    return 0;
}
