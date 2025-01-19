#include<stdio.h>
void cpy(char a[], char b[]){
    int i;
    for(i=0; b[i]!='\0'; i++){
        a[i]=b[i];
    }
    a[i]='\0';
}
int main(){
    char a[1000], b[1000];
    printf("Enter String: ");
    gets(a);
    for(int i=0; a[i]!='\0'; i++){
        if(a[i]=='\n'){
            a[i]='\0';
            break;
        }  
    }
    cpy(b,a);
    printf("Copied String: %s",b);
    return 0;
}