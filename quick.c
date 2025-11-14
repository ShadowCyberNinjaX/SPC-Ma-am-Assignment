#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median3(int *arr, int left, int right)
{
    int mid = (left + right) / 2;

    // Order left, mid, right
    if (arr[left] > arr[mid])
        swap(&arr[left], &arr[mid]);
    if (arr[left] > arr[right])
        swap(&arr[left], &arr[right]);
    if (arr[mid] > arr[right])
        swap(&arr[mid], &arr[right]);

    // Place pivot at right - 1
    swap(&arr[mid], &arr[right - 1]);
    return arr[right - 1];
}

int partition(int *arr, int left, int right)
{
    int pivot = median3(arr, left, right);
    int i = left;
    int j = right - 1;

    while (1)
    {
        while (arr[++i] < pivot);  // move i right
        while (arr[--j] > pivot);  // move j left

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    // Place pivot in final place
    swap(&arr[i], &arr[right - 1]);
    return i;
}

void quicksort(int *arr, int left, int right)
{
    if (left + 2 <= right)   // ensure at least 3 elements
    {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, right);
    }
    else
    {
        // Simple manual sort for 1-2 elements
        if (left < right && arr[left] > arr[right])
            swap(&arr[left], &arr[right]);
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
