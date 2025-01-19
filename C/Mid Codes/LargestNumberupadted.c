#include<stdio.h>

int main()
{
    int a, b, c;
    printf("Enter values of a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a == b && b == c)
    {
        printf("All numbers are equal: %d\n", a);
    }
    else if (a >= b && a >= c)
    {
        printf("The largest number is a: %d\n", a);
        if (a == b)
            printf("Note: a and b are equal.\n");
        if (a == c)
            printf("Note: a and c are equal.\n");
    }
    else if (b >= a && b >= c)
    {
        printf("The largest number is b: %d\n", b);
        if (b == a)
            printf("Note: b and a are equal.\n");
        if (b == c)
            printf("Note: b and c are equal.\n");
    }
    else if (c >= a && c >= b)
    {
        printf("The largest number is c: %d\n", c);
        if (c == a)
            printf("Note: c and a are equal.\n");
        if (c == b)
            printf("Note: c and b are equal.\n");
    }

    return 0;
}