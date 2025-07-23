// Write a C++ program that includes a function to calculate the area of a circle. The function should take the radius as a parameter and return the area.
#include<iostream>
#define PI 3.1416
using namespace std;
float area(float r){
    return PI*r*r;
}
int main(){
    float r;
    cout<<"Enter Radius: ";
    cin>>r;
    cout<<"Area of Circle: "<<area(r)<<endl;
}