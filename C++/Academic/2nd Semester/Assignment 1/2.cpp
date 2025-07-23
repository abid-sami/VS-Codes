//Write a C++ program that reads two integers from the user and prints their sum.
#include<iostream>
using namespace std;
int sum(int a, int b){
    return a+b;
}


int main(){
    int a, b;
    cout<<"Enter values of A & B: "<<endl;
    cin>>a>>b;
    cout<<"Sum: "<<sum(a,b);

    return 0;
}