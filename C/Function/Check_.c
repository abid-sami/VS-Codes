//Check Small letter, Capital letter, Digit or a Special symbol

#include<stdio.h>
void ch(char c){
    if(c>='a'&&c<='z'){
        printf("Small letter\n");
    }
    else if(c>='A'&&c<='Z'){
        printf("Capital letter\n");
    }
    else if(c>='0'&&c<='9'){
        printf("Digit\n");
    }
    else{
        printf("Special symbol\n");
    }
}
int main(){
    char c;
    printf("Input:");
    scanf("%c",&c);
    ch(c);
    return 0;
}
