//Find Odd or Even Number
#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n%2==0){
    printf("Even Number");
    }
    if(n%2!=0){
    printf("Odd number");
    }
    
return 0;
}