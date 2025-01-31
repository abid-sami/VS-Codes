// Write a C++ program to create a class called Rectangle that has private member variables for length and width. Implement member functions to calculate the rectangle's area and perimeter. 
#include<iostream>
using namespace std;
class Rectangle
{
    double l,w,p,a;  
public:
    void input(){
    cin>>l>>w;
    }
    void cal(){
        a=l*w;
        p=2*(l+w);
    }
    void display(){
    cout<<"Area: "<<a<<endl;
    cout<<"Perimeter: "<<p<<endl;
    }

};
int main(){
Rectangle r;
r.input();
r.cal();
r.display();
}
