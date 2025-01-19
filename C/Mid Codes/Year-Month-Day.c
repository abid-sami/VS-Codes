//Convert days into Years, Months and Days
#include<stdio.h>

int main()
{
int d,y,m,d1;
    printf("Enter days: ");
    scanf("%d",&d);
    y=d/365;
    m=(d%365)/30;
    d1=(d%365)%30;
    printf("%d Years, %d Months, %d Days",y,m,d1);
    
    return 0;
}