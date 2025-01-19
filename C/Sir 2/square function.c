#include<stdio.h>
int square(int n)
{
    return n*n;
}
int main()
{
    int i,a[5];
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",square(a[i]));
    }

    return 0;
}
