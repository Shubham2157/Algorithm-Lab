#include <iostream>
#include<time.h>
using namespace std;

int prime(int n)
{
    if(n%n==0)
      if(n%1==0)
         if(n%2!=0)
          if(n%3!=0)
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
