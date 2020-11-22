#include<stdio.h>
#include<time.h>
int fib_divide(int n)
{
   if (n <= 1)
      return n;
   return fib_divide(n-1) + fib_divide(n-2);
}

int fib_dynamic(int n)
{
  int f[n+2];
  int i;
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}

int main ()
{
  int n;
  printf("Enter the number:\n");
  scanf("%d",&n);
  printf("%d\n", fib_divide(n));
  clock_t start,end;
  double total;
  start=clock();
  fib_divide(n);
  end=clock();
  total=((double)(end-start))/CLOCKS_PER_SEC;
  printf("\nTime Complexity fibonacci by divide and Conquer: %lf",total);
  start=clock();
  fib_dynamic(n);
  end=clock();
  total=((double)(end-start))/CLOCKS_PER_SEC;
  printf("\nTime Complexity fibonacci by dynamic Programming: %lf",total);
  return 0;
}
