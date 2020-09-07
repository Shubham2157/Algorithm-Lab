#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })

int findMaximumElement(int heap[], int n)
{
    int maximumElement = heap[0];

    for (int i = 1; i < n; ++i)
        maximumElement = max(maximumElement, heap[i]);

    return maximumElement;
}

int main(){
    int i,n;
    clock_t start,end;
    float total;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        a[i]=(rand()%100)+1;
        printf("%d ",a[i]);

    }
    start=clock();
    int m = findMaximumElement(a, n);
    end=clock();
    printf("\nMax No is %d",m);
    total=((float)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime Complexity: %f\n",total);

}
