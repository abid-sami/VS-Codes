//Write a program to reverse an Array.

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter amount of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Reversed Arrays: "<<endl;
    for(int i=n-1; i>=0; i--){
        cout<<arr[i];
    }
}