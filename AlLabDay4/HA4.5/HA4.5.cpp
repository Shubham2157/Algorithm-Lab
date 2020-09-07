#include <bits/stdc++.h>
using namespace std;

void bruteForcePatternSearch(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();

    bool found = false;

    for (int i = 0; i < n - m; ++i)
    {
        int j;
        for (j = 0; j < m; ++j)
            if (txt[i + j] != pat[j])
                break;
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found in Text!!\n";
}

int main()
{
    string TEXT, PATTERN;

    cout << "Enter Text: ";
    getline(cin, TEXT);

    cout << "Enter Pattern: ";
    getline(cin, PATTERN);

    int n = TEXT.length();
    int m = PATTERN.length();

    if (m > n)
    {
        cout << "Pattern not found in Text!!\n";
        return 0;
    }

    bruteForcePatternSearch(TEXT, PATTERN);

    return 0;
}
