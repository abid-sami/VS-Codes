//Write a C++ program that calculates the factorial of a given number using a loop.
#include<iostream>
using namespace std;
int main(){
    int n, i, f=1;
    cout<<"Enter Number: ";
    cin>>n;
    for(i=1; i<=n; i++){
        f=f*i;
    }
    cout<<"Factorial Number: "<<f<<endl;
}