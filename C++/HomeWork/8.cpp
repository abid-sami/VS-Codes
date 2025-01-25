//Write a C++ program that calculates the sum of all elements in a given array of integers. 
#include<iostream>
using namespace std;
int main(){
    int n, i, s=0;
    cout<<"Enter Array Amount: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Numbers: ";
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    for(i=0; i<n; i++){
        s=s+arr[i];
    }
    cout<<"Sum: "<<s<<endl;
}