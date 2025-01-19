//Find the largest number from 3 numbers
#include<stdio.h>

int main() {
    int a,b,c;
    printf("Input 3 Numbers: ");
    scanf("%d%d%d",&a,&b,&c);
    if (a>=b && a>=c)
        printf("%d is the largest number",a);
    else if (b>=c && b>=c)
        printf("%d is the largest number",b);
     else if (c>=a && c>=a)
        printf("%d is the largest number",c);

    return 0;
}