//Generate random password
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int n,i,x;  
    printf("Enter Password Length: ");
    scanf("%d",&n);
    if(n>=6){
        char pass[]= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$&%*?+-/";
        srand(time(NULL));
        printf("Password: ");
        for(i=0; i<n; i++){
        x=rand()%(sizeof(pass)-1);
        printf("%c",pass[x]);   
        }
    }
    else
    printf("Password length minimum 6 Character!");
    
    return 0;
}