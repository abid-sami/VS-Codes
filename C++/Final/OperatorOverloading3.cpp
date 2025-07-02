/* Write a C++ code that can add multiply two objects using the concept of operator overloading */

#include<iostream>
using namespace std;

class Complex{
    int value;
    public:
    Complex(int v=0){
        value=v;
    }
    Complex operator+(Complex const& obj){
        return Complex(value+obj.value);
    }
    Complex operator*(Complex const& obj){
        return Complex(value*obj.value);
    }
    void display(){
        cout<<value<<endl;
    }
};

int main(){
    Complex a(4),b(5);
    Complex add=a+b;
    Complex mul=a*b;

    add.display();
    mul.display();
}