#include<stdio.h>
int main()
{
    float marks;
    scanf("%f",&marks);

    if(marks>=80.0)
        printf("A+");
    else if(75.0<=marks && marks<80.0)
        printf("A");
    else if(70.0<=marks && marks<75.0)
        printf("A-");
    else if(65.0<=marks && marks<70.0)
        printf("B+");
    else if(60.0<=marks && marks<65.0)
        printf("B");
    else if(55.0<=marks && marks<60.0)
        printf("B-");
    else if(50.0<=marks && marks<55.0)
        printf("C+");
    else if(45.0<=marks && marks<50.0)
        printf("C");
    else if(40.0<=marks && marks<45.0)
        printf("D");
    else
        printf("F");

    return 0;
}

