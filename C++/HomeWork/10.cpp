//Write a C++ program that performs basic arithmetic operations (addition, subtraction, multiplication, division) on two numbers provided by the user. The user should be able to choose the operation.
#include<iostream>
using namespace std;
int main(){
    float a,b;
    char o;
    cout<<"Enter 2 Numbers: ";
    cin>>a>>b;
    cout<<"Enter Operator: ";
    cin>>o;
    switch(o){
        case '+':
        cout<<"Addition: "<<a+b<<endl;
        break;
        case '-':
        cout<<"Subtraction: "<<a-b<<endl;
        break;
        case '*':
        cout<<"Multiplication: "<<a*b<<endl;    
        break;
        case '/':
        cout<<"Division: "<<a/b<<endl;
        break;

    }

}