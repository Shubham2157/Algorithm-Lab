#include <stdio.h>
#include <time.h>
#include <stdlib.h>

quickSort()
{

}

int main()
{
    int n;
    printf("Enter the number of array to be generated : ");
    scanf("%d",&n);

    int arr[n];
    srand(0);
    int i;
    for (i = 0; i < n; i++) {
    arr[i] = rand();
    }

    printf("Given array is \n");
    printArray(arr, n);
    clock_t start,end;
	double total1;
	start=clock();
    quickSort(arr, 0, n - 1);
    end=clock();
    total1=(((double)(end-start))/CLOCKS_PER_SEC);
	printf("Time  = %f\n \n",total1);

}
