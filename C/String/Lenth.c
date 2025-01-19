//Count string using strlen
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int len=strlen(str);
    printf("%d",len);
    return 0;

}
