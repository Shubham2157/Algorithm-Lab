#include<stdio.h>

void printProductArray(int a[], int n, int product)
{
    for (int i = 0; i < n; ++i)
    printf("%d ",product / a[i]);
    printf("\n");
}
int main()
{
    int a[] = {10, 4, 1, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int product = 1;
    for (int i = 0; i < n; ++i)
        product *= a[i];

    printf("Original array:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ",a[i]);

    printf("\n");

    printf("array after operation:\n");
    printProductArray(a, n, product);

    return 0;
}
