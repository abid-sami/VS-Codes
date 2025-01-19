//Calculate 2D Point Distance
#include<stdio.h>
#include<math.h>
struct distance{
    float x,y;
}d1,d2;

int main(){
    float x,y,d;
    printf("Enter x1 & y1 values: ");
    scanf("%f %f",&d1.x,&d1.y);
    printf("Enter x2 & y2 values: ");
    scanf("%f %f",&d2.x,&d2.y);
    d=sqrt(pow((d1.x-d2.x),2)+pow((d1.y-d2.y),2));
    printf("Distance: .2%f",d);

}