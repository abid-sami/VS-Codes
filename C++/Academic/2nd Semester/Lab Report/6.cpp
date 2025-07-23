#include<iostream>
#define PI 3.1416
using namespace std;

float area(float r){
    return PI*r*r;
}

float area(float l,float w){
    return l*w;
}

float area(float b,float h){
    return 0.5*b*h;
}

int main(){
    float r,l,w,b,h;
    cout<<"Enter Radius: "<<endl;
    cin>>r;
    cout<<"Area of Circle: "<<area(r)<<endl;

    cout<<"Enter Length and Width: "<<endl;
    cin>>l>>w;
    cout<<"Area of Rectangle: "<<area(l,w)<<endl;

    cout<<"Enter Base and Height: "<<endl;
    cin>>b>>h;
    cout<<"Area of Triangle: "<<area(b,h)<<endl;
}