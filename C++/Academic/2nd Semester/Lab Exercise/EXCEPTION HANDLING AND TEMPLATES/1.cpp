/* Write a program that performs division between two numbers entered by the user. If the user 
tries to divide by zero, throw an exception and catch it to display an error message like 
"Division by zero is not allowed." Test this with different inputs, including zero as the divisor. */

#include<iostream>
using namespace std;

int remainder(int a, int b){
    if(b!=0){
        return a%b;
    }
    else{
        throw 0;
    }
}

int main(){
    int a,b,rem;
    cin>>a>>b;
    try{
        rem=remainder(a,b);
        cout<<"Remainder: "<<rem<<endl;
    }
    catch(int c){
        cout<<"Division by zero is not allowed"<<endl;
    }
}