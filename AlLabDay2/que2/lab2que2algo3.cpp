#include <iostream>
#include<time.h>
#define MAXFACTORS 1024
using namespace std;


typedef struct
{

    int size;
    int factor[MAXFACTORS + 1];
    int exponent[MAXFACTORS + 1];

} FACTORIZATION;


void FindFactorization(int x, FACTORIZATION* factorization)
{
    int i, j = 1;
    int n = x, c = 0;
    int k = 1;
    factorization->factor[0] = 1;
    factorization->exponent[0] = 1;

    for (i = 2; i <= n; i++) {
        c = 0;

        while (n % i == 0) {
            c++;


            n = n / i;

        }

        if (c > 0) {
            factorization->exponent[k] = c;
            factorization->factor[k] = i;
            k++;
        }
    }

    factorization->size = k - 1;
}

void DisplayFactorization(int x, FACTORIZATION factorization)
{

    int i;
    cout << "Prime factor of << x << = ";

    for (i = 0; i <= factorization.size; i++) {

        cout << factorization.factor[i];

        if (factorization.exponent[i] > 1)
            cout << "^" << factorization.exponent[i];

        if (i < factorization.size)
            cout << "*";

        else
            cout << "\n";
    }
}

int gcdMiddleSchoolProcedure(int m, int n)
{

    FACTORIZATION mFactorization, nFactorization;

    int r, mi, ni, i, k, x = 1, j;

    FindFactorization(m, &mFactorization);
    DisplayFactorization(m, mFactorization);


    FindFactorization(n, &nFactorization);
    DisplayFactorization(n, nFactorization);

    int min;
    i = 1;
    j = 1;
    while (i <= mFactorization.size && j <= nFactorization.size) {
        if (mFactorization.factor[i] < nFactorization.factor[j])
            i++;

        else if (nFactorization.factor[j] < mFactorization.factor[i])
            j++;

        else
        {
            min = mFactorization.exponent[i] > nFactorization.exponent[j]
                      ? nFactorization.exponent[j]
                      : mFactorization.exponent[i];

            x = x * mFactorization.factor[i] * min;
            i++;
            j++;
        }
    }

    return x;
}

int main()

{

    clock_t start,end;
    double cpu_time_used;

    int m , n;

    cout<<"Enter first number to check-"<<endl;
    cin>>m;

    cout<<"Enter second number to check-"<<endl;
    cin>>n;

    cout << "GCD(" << m << ", " << n << ") = "
         << gcdMiddleSchoolProcedure(m, n);


    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"Time complexity of the algorithm :- "<<cpu_time_used<<endl;

    return (0);
}
