/*Write a C++ program to perform arithmetic operations on two numbers and throw an exception if the 
dividend is zero or does not contain an operator.*/

#include<iostream>
using namespace std;

int main(){
    double a,b;
    char o;
    cout<<"Enter 2 numbers: "<<endl;
    cin>>a>>b;
    cout<<"Enter Operator: "<<endl;
    cin>>o;

    try{
        if(o!='+' && o!='-' && o!='*' && o!='/'){
            throw "Invalid Operator";
        }
        if(o=='/' && b=='0'){
            throw "Cant be 0";
        }

    }
    double result;

    switch(o){
        case '+':
        result=a+b;
        break;

        case '-':
        result=a-b;
        break;
}
cout<<"Result: "<<result<<endl;
catch(const char* e){
    cout<<e<<endl;
}

}