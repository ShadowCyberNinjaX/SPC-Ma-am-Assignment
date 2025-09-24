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

// Recursive function for matrix addition
void addRecursive(int i, int j) {
    if (i >= r1)  // all rows done
        return;

    if (j >= c1) {  // all columns in a row done → move to next row
        addRecursive(i + 1, 0);
        return;
    }

    // Add corresponding elements
    C[i][j] = A[i][j] + B[i][j];

    // Move to next column
    addRecursive(i, j + 1);
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

    if (r1 != r2 || c1 != c2) {
        printf("Matrix addition not possible! (Dimensions must be same)\n");
        return 0;
    }

    // Allocate matrices
    A = allocateMatrix(r1, c1);
    B = allocateMatrix(r2, c2);
    C = allocateMatrix(r1, c1);

    // Input A
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Input B
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Perform addition recursively
    addRecursive(0, 0);

    // Print result
    printf("Resultant matrix (A + B):\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    // Free memory
    freeMatrix(A, r1);
    freeMatrix(B, r2);
    freeMatrix(C, r1);

    return 0;
}
