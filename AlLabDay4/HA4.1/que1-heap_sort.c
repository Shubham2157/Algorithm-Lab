    #include<stdio.h>
    #include<time.h>
    #include<stdlib.h>
    int temp;

    void heapify(int arr[], int size, int i)
    {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[left] >arr[largest])
    largest = left;

    if (right < size && arr[right] > arr[largest])
    largest = right;

    if (largest != i)
    {
    temp = arr[i];
        arr[i]= arr[largest];
        arr[largest] = temp;
    heapify(arr, size, largest);
    }
    }

    void heapSort(int arr[], int size)
    {
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
    heapify(arr, size, i);
    for (i=size-1; i>=0; i--)
    {
    temp = arr[0];
        arr[0]= arr[i];
        arr[i] = temp;
    heapify(arr, i, 0);
    }
    }

    void main()
    {
    int arr[50000],size,i;
    clock_t start,end;
    float total;
    printf("Enter the total no. of elements:\n");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        arr[i]=rand();
    }
    start=clock();
    heapSort(arr, size);
    end=clock();
    total=((float)(end-start))/CLOCKS_PER_SEC;
    printf("Sorted elements\n");
    for (i=0; i<size; ++i)
    printf("%d\n",arr[i]);
    printf("Time Complexity of random number in Heap Sort: %f\n",total);
    for(i=0;i<size;i++)
    {
        arr[i]=i;
    }
    start=clock();
    heapSort(arr, size);
    end=clock();
    total=((float)(end-start))/CLOCKS_PER_SEC;
    printf("Time Complexity of Ascending Order in Heap Sort: %f\n",total);
    for(i=0;i<size;i++)
    {
        arr[i]=size-i;
    }
    start=clock();
    heapSort(arr, size);
    end=clock();
    total=((float)(end-start))/CLOCKS_PER_SEC;
    printf("Time Complexity of Descending Order in Heap Sort: %f\n",total);
    }
