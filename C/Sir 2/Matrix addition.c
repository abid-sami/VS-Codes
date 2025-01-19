#include<stdio.h>
int main()
{
    int row, col,i,j;
    printf("Enter row and column: ");
    scanf("%d%d",&row,&col);
    int A[row][col],B[row][col],C[row][col];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            A[i][j] = rand()%50;
            B[i][j] = rand()%25;
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    printf("Matrix A\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%2d  ",A[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%2d  ",B[i][j]);
        }
        printf("\n");
    }
    printf("Added Matrix\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%2d  ",C[i][j]);
        }
        printf("\n");
    }


    return 0;
}
