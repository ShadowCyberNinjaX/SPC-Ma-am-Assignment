#include <stdio.h>
#include <limits.h>

void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k+1][j]
                        + p[i-1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications = %d\n", m[1][n-1]);
}

int main()
{
    int n;
    printf("Enter number of matrices: "); 
    scanf("%d", &n); 
    int p[n + 1]; 
    printf("Enter %d dimensions (p0 p1 ... p%d): ", n + 1, n); 
    for (int i = 0; i <= n; i++) 
        scanf("%d", &p[i]); 
    matrixChainOrder(p, n);
    return 0;
}
