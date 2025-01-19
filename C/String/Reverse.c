//Reversed Character
#include<stdio.h>
int main(){
    char str1[100];
    printf("Input value: ");
    gets(str1);
    char str2[100];
    int len;
    for(len=0; str1[len]; len++);
    for(int i=0; i<len; i++){
        str2[i]=str1[len-1-i];
    }
    str2[len]='\0';
    printf("Reversed String: %s",str2);
    return 0;
}
