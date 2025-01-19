#include<stdio.h>
void n();
void b();
int main() {
    char c;
    printf("Enter N or B:");
    scanf("%c", &c);
    if(c == 'n'){
        n();
    }
    else if(c == 'b'){
        b();
    } 
    return 0;
}
void n(){
    printf("Salam");
}
void b(){
    printf("Bonjour");
}
