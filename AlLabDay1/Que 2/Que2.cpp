#include <iostream>

using namespace std;

int main()
{
    int size;
    int array[size];
    int j=0,k=0;
    int even_array[size],odd_array[size];

    cout<<"Enter the size of array:"<<endl;
    cin>>size;
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }

    for(int i=0;i<size;i++)
    {

        if(array[i]%2==0)
         {
             even_array[j]=array[i];
             j++;

         }
         else
         {
             odd_array[k]=array[i];
             k++;

         }


    }
    cout<<"the Even array"<<endl;
    for(int i=0;i<j;i++)
    {
        cout<<even_array[i]<<" "<<endl;
    }
    cout<<"the odd array"<<endl;
    for(int i=0;i<j;i++)
    {
        cout<<odd_array[i]<<" "<<endl;
    }

    return 0;
}
