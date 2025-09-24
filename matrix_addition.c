#include<stdio.h>
#include<stdlib.h>
int** allotematrix(int r,int c)
{
    int** matrix=(int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)
    {
        matrix[i]=(int*)malloc(c*sizeof(int));
    }
    return matrix;
}
void intmatrix(int** a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void printmatrix(int** a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void addmatrix(int** a,int** b,int** c,int r,int col)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<col;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("Resultant Matrix:\n");
    printmatrix(c,r,col);
}
void freematrix(int** a,int r)
{
    for(int i=0;i<r;i++)
    {
        free(a[i]);
    }
    free(a);
}
int main()
{
    int r,col;
    printf("enter the row and column ");
   scanf("%d %d",&r,&col);
   int** a=allotematrix(r,col);
   int** b=allotematrix(r,col);
   int** c=allotematrix(r,col);
   printf("Enter elements of first matrix:\n");
   intmatrix(a,r,col);
   printf("First Matrix:\n");
   printmatrix(a,r,col);
   printf("Enter elements of second matrix:\n");
   intmatrix(b,r,col);
   printf("Second Matrix:\n");
   printmatrix(b,r,col);
   addmatrix(a,b,c,r,col);
   freematrix(a,r);
   freematrix(b,r);
   freematrix(c,r);
   return 0;
}