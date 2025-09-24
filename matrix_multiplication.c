#include<stdio.h>
#include<stdlib.h>
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));
    return matrix;
}
void intmatrix(int** a,int rows, int cols)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void printmatrix(int** a,int rows, int cols)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void multiply(int** a, int** b, int** c, int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible.\n");
        return;
    }
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            c[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rowsA, &colsA);
    int** a = allocateMatrix(rowsA, colsA);
    printf("Enter elements of first matrix:\n");
    intmatrix(a, rowsA, colsA);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rowsB, &colsB);
    int** b = allocateMatrix(rowsB, colsB);
    printf("Enter elements of second matrix:\n");
    intmatrix(b, rowsB, colsB);

    int** c = allocateMatrix(rowsA, colsB);
    
    multiply(a, b, c, rowsA, colsA, rowsB, colsB);

    printf("Resultant matrix after multiplication:\n");
    printmatrix(c, rowsA, colsB);

    freeMatrix(a, rowsA);
    freeMatrix(b, rowsB);
    freeMatrix(c, rowsA);

    return 0;
}