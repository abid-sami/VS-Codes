#include<stdio.h>

int main()
{
    float M;
    scanf("%f",&M);
    if (M>=80)
    printf("A");
    else if (M>=65)
        printf("B");
    else if(M>=50)
        printf("C");
    else if (M>=40)
        printf("D");
    else if(M>=33)
    printf("E");
    else if(M<=32)
    printf("Fail");

    return 0;
}