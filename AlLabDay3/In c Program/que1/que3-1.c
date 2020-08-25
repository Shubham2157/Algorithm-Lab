#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n - 1; i++) {


        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int Binary_Search(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;


		if (arr[mid] > x)
			return Binary_Search(arr, l, mid - 1, x);


		return Binary_Search(arr, mid + 1, r, x);
	}


	return -1;
}

int main(void)
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
    printf("\nUnsorted array : ");
    for (i = 0; i < n; i++) {
    printf(" %d ",arr[i]);
    }
    sort(arr,n);
    printf("\nSorted array : ");
    for (i = 0; i < n; i++) {
    printf(" %d ",arr[i]);
    }

    int x;
    printf("\n\nEnter the number to be find in array generated : ");
    scanf("%d",&x);

	clock_t start,end;
	double total1;
	start=clock();
    int result = Binary_Search(arr, 0, n - 1, x);
    end=clock();
    total1=(((double)(end-start))/CLOCKS_PER_SEC);
	printf("Time  = %f\n \n",total1);

	(result == -1) ? printf("Element is not present in the array")
				: printf("Element is present at index %d",
							result);
	return 0;
}
