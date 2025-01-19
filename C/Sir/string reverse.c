#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000],str1[1000];
    gets(str);
    puts(str);
    strcpy(str1,str);
    int n = strlen(str);
    for(int i=0;i<n/2;i++)
    {
        int temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }
    puts(str);
    if(strcmp(str,str1)==0)
        printf("\nPalindrome");
    else
         printf("\nNot Palindrome");


}
