#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median3(int A[],int l,int r)
{
    int mid=(l+r)/2;
    if(A[mid]>A[r])
    {
        swap(&A[mid],&A[r]);
    }
    if(A[l]>A[r])
    {
        swap(&A[l],&A[r]);
    }
    if(A[l]>A[mid])
    {
        swap(&A[mid],&A[l]);
    }
    swap(&A[mid],&A[r-1]);
    return A[r-1];
}

int partition(int A[],int l,int r)
{
    int x=median3(A,l,r);
    int i=l;
    int j=r-1;

    while(1)
    {
        while(A[++i]<x);
        while(A[--j]>x);
        if(i<j)
        {
            swap(&A[i],&A[j]);
        }
        else{
            break;
        }
    }
    swap(&A[r-1],&A[i]);
    return i;
}

void quicksort(int A[],int l,int r)
{
    if (l + 2 <= r)
    {
        int m = partition(A, l, r);
        quicksort(A, l, m - 1);
        quicksort(A, m + 1, r);
    }
    else if (l < r)
    {
        if (A[l] > A[r])
            swap(&A[l], &A[r]);
    }
}


int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
