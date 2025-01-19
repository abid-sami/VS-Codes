//Grading Marks using Switch
#include<stdio.h>

int main()
{
    char ch;
    printf("Input Grade: ");
    scanf("%c",&ch);
    switch(ch)
    {
    case 'A':
            printf("4.00");
        break;
    case 'B':
        printf("3.50");
        break;
    case 'C':
        printf("3.00");
        break;
    case 'D':
        printf("2.50");
        break;
    case 'E':
        printf("2.00");
        break;
    case 'F':
        printf("0.00");
        break;
        
    default:
        printf("Invalid Input");
        break;
    }


    return 0;
}