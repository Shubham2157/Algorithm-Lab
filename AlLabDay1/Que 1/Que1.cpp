#include <iostream>
#include<stdlib.h>

using namespace std;

void random_array(int,int,int);

int main()
{
    int upper=100,lower=0,cnt;
    cout<<"Enter the size of array:"<<endl;
    cin>>cnt;
    random_array(lower,upper,cnt);

    return 0;
}

void random_array(int l,int u,int c)
{
    int a[c],i;
    int smallest=a[0];
    int largest=0;
    for(int i=0;i<5;i++)
         a[i]=((rand()%(u-l+1))+l);


    for(int i=0;i<c;i++)
    {
        cout<<a[i]<<endl;
    }
    for(int i=0;i<c;i++)
    {
        if(a[i]<smallest)
        {
            smallest=a[i];
        }
    }

    for(int i=0;i<c;i++)
    {
        if(a[i]>largest)
        {
            largest=a[i];
        }
    }
    cout<<endl<<"the smallest and the largest no are : "<<smallest<<" & "<<largest<<endl;

}

