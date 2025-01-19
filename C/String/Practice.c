#include <stdio.h>

int main() {
    char str[100];
    printf("Input value: ");
    gets(str);
    char str2[100];
    int len=0;
    for(int i=0; str[i]!='\0'; i++){
        len++;
    }
    for(int j=0; str[j]!='\0'; j++){
        str[j]=str[i];
    }
    printf("Reversed String: %c",str2);

    return 0;
}