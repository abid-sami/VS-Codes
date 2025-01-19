// Count the length of array
#include<stdio.h>
int strlen(char str[]){
    int length=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        ++length;
    }
    return length;
}
int main(){
    char a[1000];
    printf("Input: ");
    gets(a);
    puts(a);
    printf("Length = %d\n",strlen(a));
    return 0;
}