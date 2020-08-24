#include <iostream>
#include<time.h>
using namespace std;

int prime(int n)
{

    if (n <= 1)
        return 0;
    else if (n <= 3)
        return 1;

    else if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}

int main()
{
    clock_t start,end;
    double cpu_time_used;
    int n;
    cout<<"Enter a number to check-"<<endl;
    cin>>n;
    start=clock();
    if(prime(n)==1)
    {
        cout<<"Yes "<<n<<" is a prime number"<<endl;
    }
    else
         cout<<"No "<<n<<" is not a prime number"<<endl;

    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"Time complexity of the algorithm :- "<<cpu_time_used<<endl;
    return 0;
}
