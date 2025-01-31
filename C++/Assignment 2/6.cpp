// Write a C++ program to create a class called Triangle that has private member variables for the lengths of its three sides. Implement member functions to determine if the triangle is equilateral, isosceles, or scalene.
#include<iostream>
using namespace std;
class Triangle{
    float a,b,c;
public:
    void input(){
    cin>>a>>b>>c;
    }
    void output(){
    if(a==b && b==c){
        cout<<"Equlateral";
    }
    else if(a==b || b==c || a==c){
        cout<<"Isoscale";
    }
    else if(a!=b && b!=c && a!=c){
        cout<<"Scalene";
    }
    }
};
int main(){
    Triangle t;
    t.input();
    t.output();

}


