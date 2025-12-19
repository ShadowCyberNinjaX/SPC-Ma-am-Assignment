#include <stdio.h>
#include <stdlib.h>

void merge(int A[],int l,int r,int mid)
{
    int i=l,j=mid+1,k=l;
    int* B=(int*)malloc(r+1*sizeof(int));
    while(i<=mid && j<=r)
    {
        if(A[i]<=A[j])
        {
            B[k]=A[i];
            i++;
        }
        else{
            B[k]=A[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        B[k]=A[j];
        j++;
        k++;
    }
    for(k=l;k<=r;k++)
    {
        A[k]=B[k];
    }
    free(B);
}

void mergesort(int A[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(A,l,mid);
        mergesort(A,mid+1,r);
        merge(A,l,r,mid);
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergesort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");

    free(arr);
    return 0;
}
