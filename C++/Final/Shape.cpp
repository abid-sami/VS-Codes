#include<iostream>
#define PI 3.1416
using namespace std;

class Shape{
    public:
    float area, volume;
    void display(){
        cout<<"Area: "<<area<<endl;
        cout<<"Volume: "<<volume<<endl;
    }
};

class Rectangle:public Shape{
    float length, width;
    public:
    Rectangle(float l, float w){
        length=l;
        width=w;
    }
    void calculate(){
        area=length*width;
    }
    void display();
};

class Circle:public Shape{
    float radius;
    public:
    Circle(float r){
        radius=r;
    }
    void calculate(){
        area=PI*radius*radius;
    }
};

class Triangle:public Shape{
    float base, height;
    public:
    Triangle(float b, float h){
        base=b;
        height=h;
    }
    void calculate(){
        area=0.5*height*base;
    }
};

int main(){
    Rectangle r(4,5);
}