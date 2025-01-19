#include<stdio.h>
int count(char n[]){
    int len=0;
    for(int i=0; n[i]!='\0'; i++){
        len++;
    }
    return len;
}

int main(){
    char n[100], i;
    printf("Enter String: ");
    gets(n);
    for(i=0; n[i]!='\0'; i++){
        if(n[i]=='\n'){
            n[i]='\0';
        break;   
        }
    }
    int l=count(n);
    printf("Lenth: %d",l);
    return 0;
}