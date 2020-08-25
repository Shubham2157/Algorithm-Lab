#include<stdio.h>
double square_root(double num)
{
 double temp,sqrt;
 sqrt = num/2;
 temp=0;
 while(sqrt!= temp)
 {
  temp=sqrt;
  sqrt= ((num/temp)+temp)/2;
 }

 return sqrt;
}

int main()
{
 double n;
 printf("\nEnter the numbers\n");
 scanf("%lf", &n);
 int sq;
 sq = (square_root(n));
 printf("\nThe square root of %lf is %d\n", n,sq);
}
