#include<iostream>
#include<math.h>

using namespace std;

void nonzero_element(int a[10][10],int n)
{
    int c=0,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (a[i][j]!=0)
                c++;
        }
    }
    cout<<"Number of non-zero elements : "<<c<<endl;
}

void minor_diagonal(int a[10][10],int n)
{
    cout<<"Elements below minor diagonal : ";
    int i,j;
     for(i=1;i<n;i++)
     {
         for(j=n-1;j>=n-i;j--)
         {
             cout<<" "<<a[i][j];
         }
     }
     cout<<endl;
}

void sum_of_leading_diagonal(int a[10][10],int n)
{
    int sum =0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum +=a[i][j];
        }
    }
    cout<<"Sum of elements above leading diagonal : "<<sum<<endl;
}

void diagonal_product(int a[10][10],int n)
{
    int diag1=1,diag2=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                diag1 *=a[i][j];
            }
        }
    }
    int j=n-1;
    for(int i=0;i<n;i++)
    {
        diag2 *=a[i][j];
        j--;
    }
    cout<<"the product of diagonal left to right -> "<<diag1<<endl;
    cout<<"the product of diagonal right to left -> "<<diag2<<endl;
}

int main()
{
    int a[10][10],i,j,n;
    cout<<"Enter order of the square matrix -> "<<endl;
    cin>>n;
    cout<<"Enter the elements of matrix -> "<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
   cin>>a[i][j];

    nonzero_element(a,n);
    minor_diagonal(a,n);
    sum_of_leading_diagonal(a,n);
    diagonal_product(a,n);

    return 0;
}
