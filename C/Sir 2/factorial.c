#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    long long int fact=1;
    if(n==0)
        fact = 1;
    else
        for(i=1; i<=n; i++)
        {
            fact = fact*i;
        }
    printf("Factorial(%d) = %lld\n",n,fact);



    return 0;
}
