// euclid

#include <iostream>
#include<time.h>
using namespace std;

int euclid(int a, int b)
{

	while (a != b)
	{

		if (a > b)
		   a = a - b;
		else
		   b = b - a;
	}

	return a;
}

int main()
{

    clock_t start,end;
    double cpu_time_used;

	int a;
	int b;

	cout<<"Enter first number to check-"<<endl;
    cin>>a;

    cout<<"Enter second number to check-"<<endl;
    cin>>b;

	cout<<"GCD of "<<a << " and "<<b <<" are "<<euclid(a, b)<<endl;

	end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"Time complexity of the algorithm :- "<<cpu_time_used<<endl;
    return 0;
}
