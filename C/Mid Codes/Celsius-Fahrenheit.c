//Convert Celsius to Fahrenheit 
#include <stdio.h>
int main()
{
    float c, f;
    printf("Enter Celsius: ");
    scanf("%f", &c);
    f = ((c * 9) / 5) + 32;
    printf("Fahrenheit: %f", f);
    return 0;
}