#include <iostream>
#include<time.h>
using namespace std;

int main() {

    clock_t start,end;
    double cpu_time_use;
    start=clock();

    int i, n;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";


    end=clock();
    cpu_time_use=(double(end-start))/CLOCKS_PER_SEC;
    cout<<"Time complexity of the algorithm :- "<<cpu_time_use;

    return 0;
}
