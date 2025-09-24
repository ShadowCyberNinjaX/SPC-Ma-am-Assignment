#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int median3(int *arr,int left,int right)
{
    int mid=(left+right)/2;
    if(arr[left]>arr[mid])
        swap(&arr[left], &arr[mid]);
    if(arr[left]>arr[right])
        swap(&arr[left], &arr[right]);
    if(arr[mid]>arr[right])
        swap(&arr[mid],&arr[right]);
    swap(&arr[mid],&arr[right-1]);
    return arr[right-1];
}
int partition(int *arr,int left,int right)
{
    int pivot=median3(arr,left,right);
    int i=left;
    int j=right-1;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
       {
         j--;
       } 
       if(i<j)
       {
        swap(&arr[i],&arr[j]);
       }
    }
    swap(&arr[i],&arr[right-1]);
    return i;
}
void insert(int *arr,int left,int right)
{
    for(int i=left+1;i<=right;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=left && arr[j]>key)
       { arr[j+1]=arr[j];
        j--;
        }
    arr[j+1]=key;
    }
}
void quicksort(int *arr,int left,int right)
{
    if(left+10<=right)
    {
        int pivot=partition(arr,left,right);
        quicksort(arr,left,pivot-1);
        quicksort(arr,pivot+1,right);
    }
    else
    insert(arr, left, right);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    quicksort(arr, 0, n - 1);
    
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}