#include<stdio.h>
int sum(int a, int b);
int main()
{
    int a=9, b=10;
    printf("%d\n",sum(a,b));

    return 0;
}
int sum(int b, int a)
{
    printf("%d\t%d\n",a,b);
    return a+b;
}


