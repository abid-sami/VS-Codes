//Swap two numbers
#include<stdio.h>

int main()
{
    int a,b,temp;
    printf("Enter the values of a & b: ");
    scanf("%d %d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("Swap results: %d %d",a,b);
    
    return 0;
}