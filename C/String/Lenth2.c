//Count string 
#include<stdio.h>
int main(){
    char str[100];
    printf("Input value: ");
    gets(str);
    int len=0;
    for(int i=0; str[i]!='\0'; i++)
    len++;
    printf("%d",len);

    return 0;

}