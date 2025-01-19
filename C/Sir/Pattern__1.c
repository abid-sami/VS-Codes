#include<stdio.h>
int main()
{
    int i,j,row,col,n,d=0;
    //scanf("%d%d",&row,&col);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=n;j>i;j--)
        {
            printf("  ");
        }
        for(int k=1;k<=i;k++)
        {
            printf("* ");
        }
        printf("\n");
    }



    return 0;
}
