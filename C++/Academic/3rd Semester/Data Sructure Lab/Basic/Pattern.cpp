//Write a Program to create a pyramid pattern using C/C++.

#include<iostream>
using namespace std;

int main(){
    int r;
    cout<<"Enter the number of rows: ";
    cin>>r;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=r-i; j++){
            cout<<" ";
        }
        for(int k=1; k<=2*i-1; k++){
            cout<<"*";
        }
        cout<<endl;
    }
}