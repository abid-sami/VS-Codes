#include<iostream>
using namespace std;

class Complex{
    int value;
    public:
    Complex(int v){
        value=v;
    }
    Complex operator+(Complex const& obj){
        return(value+obj.value);
    }
    Complex operator*(Complex const& obj){
        return(value*obj.value);
    }
    void display(){
        cout<<value<<endl;
    }
};

int main(){
    Complex a(3),b(2);
    Complex add=a+b;
    Complex mul=a*b;

    add.display();
    mul.display();
}