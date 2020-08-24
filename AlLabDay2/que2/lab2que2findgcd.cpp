#include<stdio.h>
#include<stdlib.h>
int c1=0,c2=0,c3=0;
int a,b;
int main()
{
	while(1){
	c1=0;
	c2=0;
	c3=0;
	int res=0;
	printf("Enter two numbers to find GCD - ");
	scanf("%d %d",&a,&b);
	printf("\nEuclidean Approach :\n");
	res=gcd1(a,b);
	printf("Result - %d\nFrequency count - %d\n",res,c1);
	printf("\nConsecutive Integer Divison :\n");
	res=gcd2(a,b);
	printf("Result - %d\nFrequency count - %d\n",res,c2);
	printf("\nMiddle School Approach :\n");
	res=gcd3(a,b);
	printf("Result - %d\nFrequency count - %d\n",res,c3);
}
return 0;
}

int gcd1(int a, int b)
{
	int t;
	while (b != 0)
	{
		c1++;
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int gcd2(int a, int b)
{
	if (a > b)
	gcd2(b, a);
	else
	{
		int i;
		for (i = a; i > 0; i--)
		{
			c2++;
			if ((b % i == 0) && (a % i == 0))
				return i;
		}
	}
}

int gcd3(int a, int b)
{
	if (a > b)
	gcd3(b, a);
	else
	{
	int ind = 2; int gcd = 1; int ub = a;
	for (ind = 2; ind <= ub; ind++)
	{
		c3++;
		while (((a % ind) == 0) && ((b % ind) == 0))
		{
			//c3++;
			gcd = gcd * ind;
			b = b / ind;
			a = a / ind;
			if (a == 0 || b == 0)
			return gcd;
		}
	}
	return gcd;
	}
}
