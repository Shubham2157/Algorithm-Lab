#include <iostream>
#include<time.h>
#include<math.h>

using namespace std;

void prime_no_1(int n)
{
    int i, flag=0;
    for (i=2;i<n;i++)
    {
        if (n%i==0)
        {
            cout<<"The number is not prime by Algo 1"<<endl;
            flag=1;
            break;
        }
    }
    if (flag==0)
        cout<<" The number is prime by Algo 1 "<<endl;
}

void prime_no_2(int n)
{
    int i, flag=0;
    for (i=2;i<n/2;i++)
    {
        if (n%i==0)
        {
            cout<<"The number is not prime by Algo 2"<<endl;
            flag=1;
            break;
        }
    }
    if (flag==0)
        cout<<" The number is prime by Algo 2"<<endl;
}

void prime_no_3(int n)
{
    int i, flag=0;
    for (i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            cout<<"The number is not prime by Algo 3"<<endl;
            flag=1;
            break;
        }
    }
    if (flag==0)
        cout<<" The number is prime by Algo 3 "<<endl;
}

int main()
{
    int n;
    for(int i=0;i<10;i++)
    {

    cout<<"Enter the value of n "<<endl;
    cin>>n;

    clock_t start1,end1,start2,end2,start3,end3;

    start1=clock();
    prime_no_1(n);
    end1=clock();

    start2=clock();
    prime_no_2(n);
    end2=clock();

    start3=clock();
    prime_no_3(n);
    end3=clock();


    double time_taken1=(((double)(end1-start1))/CLOCKS_PER_SEC);
    double time_taken2=(((double)(end2-start2))/CLOCKS_PER_SEC);
    double time_taken3=(((double)(end3-start3))/CLOCKS_PER_SEC);

    cout<<"Time taken in seconds to execute n = "<<n << endl
    << "Time taken by Algo1 = " << time_taken1<< endl << " Time taken by Algo 2 " << time_taken2 << endl << " Time taken by Algo 3 " << time_taken3 <<endl;

    }

return 0;


}
