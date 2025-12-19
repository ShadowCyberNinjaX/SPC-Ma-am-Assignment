#include<stdio.h>
#include<stdlib.h>

void selection(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[min]>A[j])
            {
                min=j;
            }
        }
        int temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}

int main()
{
    int n;
    printf("enter the no. of elements: ");
    scanf("%d",&n);
    int* A=(int*)malloc(n*sizeof(int));
    printf("enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("sort by selection sort\n");
    selection(A,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
    return 0;
}