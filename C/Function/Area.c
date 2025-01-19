//Calculate Area of Square, Circle & Triangle 
#include<stdio.h>
#define PI 3.1416

float square(float n){
    return n*n;
}
float circle(float r){
    return PI*r*r;
}
float triangle(float b,float h){
    return 0.5*b*h;
}
int main(){
    float x,h;
    printf("Input values:");
    scanf("%f%f",&x,&h);
    float a=square(x);
    printf("Square:%.2f\n",a);
    float b=circle(x);
    printf("Circle:%.2f\n",b);
    float c=triangle(x,h);
    printf("Triangle:%.2f\n",c);
    return 0;
}
