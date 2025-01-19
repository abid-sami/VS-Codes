#include<stdio.h>
void circle(float r, float *A, float *C)
{
    *A = 3.1415*r*r;
    *C = 2*3.1415*r;
}
int main()
{
    float a, b;
    circle(5.0,&a,&b);
    printf("Area = %f\nCircumference = %f\n",a,b);

}
