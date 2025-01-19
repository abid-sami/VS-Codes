//C program to convert USD to BDT
#include <stdio.h>
int main()
{
    int usd, bdt;
    printf("Enter BDT: ");
    scanf("%d", &bdt);
    usd = (bdt / 122.5);
    printf("Convert: %d\n", usd);
    float c = bdt - (usd * 122.5);
    printf("Money Return: %.2f", c);
    return 0;
}