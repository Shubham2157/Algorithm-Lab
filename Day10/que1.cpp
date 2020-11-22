#include <bits/stdc++.h>
#include<time.h>
using namespace std;

int max(int a, int b);
int lcs_dynamic( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs_dynamic(X, Y, m-1, n-1);
    else
        return max(lcs_dynamic(X, Y, m, n-1), lcs_dynamic(X, Y, m-1, n));
}
  int lcs_divcor( char *X, char *Y, int m, int n )
{
	int L[m + 1][n + 1];
	int i, j;

	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
		if (i == 0 || j == 0)
			L[i][j] = 0;

		else if (X[i - 1] == Y[j - 1])
			L[i][j] = L[i - 1][j - 1] + 1;

		else
			L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	return L[m][n];
}
int max(int a, int b)
{
    return (a > b)? a : b;
}

int main()
{
    char X[] = "CDFSTZKGGBZ";
    char Y[] = "GXBATKSBZK";

    int m = strlen(X);
    int n = strlen(Y);
    clock_t start,end;
    start=clock();
    cout<<"Length of LCS is "<< lcs_dynamic( X, Y, m, n ) ;
    end=clock();
    double time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
    cout<<"\nExecution Time is seconds for Dynamic Method = " <<time_taken;

    start=clock();
    cout<<"\nLength of LCS is "<< lcs_divcor( X, Y, m, n ) ;
    end=clock();
    double time_taken2=(((double)(end-start))/CLOCKS_PER_SEC);
    cout<<"\nExecution Time is seconds for Divide and Conqure method  = "<<time_taken2;
    return 0;
}
