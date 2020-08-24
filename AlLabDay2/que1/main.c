#include<stdio.h>
#include<time.h>
#include<math.h>

void prime_no_1(int n)
{
    int i, flag=0;
    for (i=2;i<n;i++)
    {
        if (n%i==0)
        {
            printf("The number is not prime by Algo 1\n");
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf(" The number is prime by Algo 1\n");
}

void prime_no_2(int n)
{
    int i, flag=0;
    for (i=2;i<n/2;i++)
    {
        if (n%i==0)
        {
            printf("The number is not prime by Algo 2\n");
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf(" The number is prime by Algo 2\n");
}

void prime_no_3(int n)
{
    int i, flag=0;
    for (i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            printf("The number is not prime by Algo 3\n");
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf(" The number is prime by Algo 3\n");
}

int main()
{
    int n;
    for(int i=0;i<10;i++)
    {

    printf("Enter the value of n\n");
    scanf("%d", &n);

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
    
    printf("Time taken in seconds to execute n= %d\nAlgo1 = %f\nAlgo2 = %f\nAlgo3= %f\n",n,time_taken1,time_taken2,time_taken3);
    
    }

return 0;


}