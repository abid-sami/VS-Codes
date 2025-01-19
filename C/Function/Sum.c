#include<stdio.h>
int sum(int a, int b);
int main(){
    int a,b;
    printf("Input Numbers:");
    scanf("%d %d", &a, &b);
    int r=sum(a,b);
    printf("Result: %d",r);
    return 0;
}
int sum(int a, int b){
    return a+b;
}