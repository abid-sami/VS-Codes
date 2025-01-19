//Find Leap Year

#include<stdio.h>
int main()
{
    int y;
    printf("Enter year: ");
    scanf("%d",&y);
    if (y%400==0)
    printf("%d is Leap year",y);
    else if (y%100==0)
    printf("%d is not Leap year",y);
    else if (y%4==0)
    printf("%d is Leap year",y);
    else
    printf("%d is not Leap year",y);
    
    return 0;
}