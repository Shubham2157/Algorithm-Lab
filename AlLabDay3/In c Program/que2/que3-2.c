#include<stdio.h>
void UDF1(int a[],int n)
{
    int i,j,x,flag=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        count =0;
        for(j=0;j<n;j++)
            if(a[i]==a[j])
                count++;
        if(count> n/2)
        {
            flag=1;
            x=a[i];
            break;
        }
    }
    if(flag==1)
        printf("\n%d occurs more than %d times in the array",x,n/2);
    else
        printf("\nNo number occurs more than %d in the array",n/2);
}
void UDF2(int a[],int n)
{
    int i,j,y,x=0,flag=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        y =a[x++];
        if(y==a[i])
            count++;
        if(count> n/2)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("\n%d occurs more than %d times in the array",y,n/2);
    else
        printf("\nNo number occurs more than %d in the array",n/2);
}
void main()
{
    int n;
    printf("Enter the no. of elements in the array");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in the array");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    UDF1(a,n);
    UDF2(a,n);
}
