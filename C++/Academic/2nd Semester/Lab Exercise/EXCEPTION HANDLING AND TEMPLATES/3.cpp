/*Write a program that prompts the user to enter their age. If the user enters an age less than 0or 
greater than 150, throw an exception and catch it to display a message like "Invalid age 
entered." Test this with valid and invalid age inputs to ensure correct handling. */

#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"Enter age "<<endl;
    cin>>a;
    try{
        if(a<=0 || a>=150){
            throw a;
        }
        cout<<"Valid age"<<endl;
    }
    catch(int b){
        cout<<"Invalid age entered."<<endl;
    }
}