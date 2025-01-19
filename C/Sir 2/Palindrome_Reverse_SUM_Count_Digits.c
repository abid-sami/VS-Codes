#include<stdio.h>
int main()
{
    int n,digit=0,sum=0,rev=0,rem;
    scanf("%d",&n);
    int temp=n;
    while(n)
    {
        rem = n%10;
        digit++;
        sum = sum+rem;
        rev = rev*10 + rem;
        n=n/10;
    }
    printf("Digit = %d\n",digit);
    printf("Sum = %d\n",sum);
    printf("Reverse = %d\n",rev);

    return 0;
}
