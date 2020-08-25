#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void linear(int a[],int n, int key){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(a[i]==key){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Element %d is found at %d position\n",key,i);
    }else
    {
        printf("Element not found");
    }
}

int main(){
    int i,n,key;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        a[i]=(rand()%100)+1;
        printf("%d ",a[i]);

    }

    printf("Enter the element to be searched : ");
    scanf("%d",&key);

    clock_t start,end;
    start=clock();
    linear(a,n,key);
    end=clock();
    double time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
    printf("Execution Time is %f seconds",time_taken);


    return 0;

}
