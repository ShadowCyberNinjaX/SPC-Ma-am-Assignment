#include <stdio.h>
#include <stdlib.h>
int r1, c1, r2, c2;
int **A, **B, **C;

int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));
    return matrix;
}

// Recursive function to multiply matrices
void multiplyRecursive(int i, int j, int k) {
    
    if (i >= r1)
        return;


    if (j >= c2) {
        multiplyRecursive(i + 1, 0, 0);
        return;
    }

    if (k >= c1) {
        multiplyRecursive(i, j + 1, 0);
        return;
    }

    C[i][j] += A[i][k] * B[k][j];

    multiplyRecursive(i, j, k + 1);
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

int main() {
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }
    A = allocateMatrix(r1, c1);
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    B=allocateMatrix(r2, c2);
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    C=allocateMatrix(r1, c2);
    // Initialize result matrix
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            C[i][j] = 0;

    // Start recursion
    multiplyRecursive(0, 0, 0);

    printf("Resultant matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    freeMatrix(A, r1);
    freeMatrix(C, r2);
    freeMatrix(C, r1);
    return 0;
}
