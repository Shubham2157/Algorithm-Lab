#include <iostream>
using namespace std;

void swap(int a, int b, int c)
{
    int k=0;
    k=a;
    a=b;
    b=c;
    c=k;
    cout<<"the values after swapping: a -> "<<a<<" b -> "<<b<<" c-> "<<c<<endl;

}
int main()
{
    int a, b,c;
    cout<<"Enter the value of three integer : ";
    cin>>a>>b>>c;
    cout<<"____________________________________________________________"<<endl<<endl;
    cout<<"the values before swapping: a -> "<<a<<" b -> "<<b<<" c -> "<<c<<endl<<endl;
    cout<<"============================================================"<<endl<<endl;
    swap(a,b,c);
    return 0;
}
