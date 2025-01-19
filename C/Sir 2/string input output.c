#include<stdio.h>
int main()
{
    char str1[100],str2[5],str3[50];
    /*printf("Input with format specifier: ");
    scanf("%s",str1);
    puts(str1);
    printf("Input with gets: ");
    gets(str2);
    puts(str2);*/
    printf("Input with fgets: ");
    fgets(str3,10,stdin);
    puts(str3);
}
