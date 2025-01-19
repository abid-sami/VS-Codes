#include<stdio.h>
#define PI 3.1416
float square(float n)
{
    return n*n;
}
float circle(float r)
{
    return PI*square(r);
}
float triangle(float base,float height)
{
    float area;
    area = 0.5*base*height;
    return area;
}
float sphere(float r)
{
    return (4.0/3)*PI*r*r*r;
}
int main()
{
    float a = 5.5;
    printf("Area of Sphere = %.3f\n",sphere(3.0));
    printf("Area of Triangle = %.3f\n",triangle(3.0,8));
    printf("Area of Circle = %.3f\n",circle(a));

    return 0;
}

