#include<stdio.h>
int len(char str[]){
    int lenth=0;
    for(int i=0; str[i]!='\0'; i++){
        ++lenth;
    }
    return lenth;
}
int main(){
    char a[1000];
    printf("Enter String: ");
    gets(a);
    printf("Lenth: %d",len(a));
    return 0;
}