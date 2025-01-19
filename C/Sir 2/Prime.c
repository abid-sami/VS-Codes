#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int f=1;
    if(n>1)
    {
        for(i=2; i<=n/2; i++)
        {
            if(n%i==0)
            {
                f=0;
                break;
            }

        }
        if(f==1)
            printf("%d is a prime number",n);
        else
            printf("%d is a not prime number",n);
    }
    else
        printf("Invalid input");


    return 0;
}

