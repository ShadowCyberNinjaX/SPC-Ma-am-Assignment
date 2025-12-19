#include<stdio.h>
#include<stdlib.h>

int n1,n2;

void merge(int a[],int b[],int c[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
        c[k++] = a[i++];

    while (j < n2)
        c[k++] = b[j++];
}

int main() {
    printf("Enter number of elements for 1st sorted array: ");
    scanf("%d", &n1);

    int *a= (int*)malloc(n1 * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    printf("Enter number of elements for 2nd sorted array: ");
    scanf("%d", &n2);

    int *b= (int*)malloc(n2 * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d", &b[i]);
    int n=n1+n2;
    int *c= (int*)malloc(n * sizeof(int));
    merge(a,b,c);
    printf("Merged array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", c[i]);
    
    printf("\n");

    free(a);
    free(b);
    free(c);
    return 0;
}