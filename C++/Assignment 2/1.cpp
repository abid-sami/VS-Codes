//Write a C++ program to implement a class called Circle that has private member variables for radius. Include member functions to calculate the circle's area and circumference.
 #include<iostream>
 #define PI 3.1416
using namespace std;
class Circle
{
    float radius,a,c;  
public:
    void input(){
    cin>>radius;
    }
    void area(){
        a=PI*radius*radius;
    }
    void circumference(){
        c=2*PI*radius;
    }
    void display(){
    cout<<"Area: "<<a<<endl;
    cout<<"Circumference: "<<c<<endl;
    }

};
int main(){
Circle c;
c.input();
c.area();
c.circumference();
c.display();
}