#include<stdio.h>

int main(){
    float pi = 3.14159;
    float r;
    printf("Enter Radius: ");
    scanf("%f",&r);
    float area = pi*r*r;
    printf("Your Area is: %f",area);
    return 0;
}