#include<stdio.h>
int main()
{
    char ch;
    scanf("%c",&ch);
    //(a-z)
    if(ch>='a' && ch<='z')
        printf("Small Letter");
    else if (ch>='A' && ch<='Z')
        printf("Capital Letter");
    else if (ch>='0' && ch<='9')
        printf("Digit");
    else
        printf("Special character");



    return 0;
}


