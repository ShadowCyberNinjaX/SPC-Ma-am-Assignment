#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = (n/2) - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void minheapsort(int arr[], int n)
{
    buildMinHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    printf("enter the no. of elements to be sorted: ");
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    printf("enter the elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("the array is :\n");
    printarray(a,n);
    minheapsort(a,n);
    printf("the sorted array is: \n");
    printarray(a,n);
    return 0;
}