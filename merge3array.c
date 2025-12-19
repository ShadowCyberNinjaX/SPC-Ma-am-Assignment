#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int b[],int c[],int n1,int n2)
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

void merge3(int a[],int b[],int c[],int temp[],int m[],int n1,int n2,int n3)
{
    merge(a,b,temp,n1,n2);
    merge(temp,c,m,n1+n2,n3);  
}


int main() {
    int n1,n2,n3;
    printf("Enter number of elements for 1st sorted array: ");
    scanf("%d", &n1);

    int *a= (int*)malloc(n1 * sizeof(int));//1st sorted array
    printf("Enter elements:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    printf("Enter number of elements for 2nd sorted array: ");
    scanf("%d", &n2);

    int *b= (int*)malloc(n2 * sizeof(int));//2nd sorted array
    printf("Enter elements:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d", &b[i]);
    printf("Enter number of elements for 3rd sorted array: ");
    scanf("%d", &n3);

    int *c= (int*)malloc(n3 * sizeof(int));//3rd sorted array
    printf("Enter elements:\n");
    for (int i = 0; i < n3; i++)
        scanf("%d", &c[i]);
    int n=n1+n2;
    int *temp= (int*)malloc(n * sizeof(int));//temp array
    int *m= (int*)malloc(n1+n2+n3 * sizeof(int));//final merged array

    merge3(a,b,c,temp,m,n1,n2,n3);

    printf("Merged array:\n");
    for (int i = 0; i < n1+n2+n3; i++)
        printf("%d ", m[i]);
    
    printf("\n");

    free(a);
    free(b);
    free(c);
    free(temp);
    free(m);
    return 0;
}