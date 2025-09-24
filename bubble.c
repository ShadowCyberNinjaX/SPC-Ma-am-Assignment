#include<stdio.h>
#include<stdlib.h>

int bubble(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if (a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    printf("----------BUBBLE SORT----------");
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
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    bubble(a,n);
    printf("the sorted array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}