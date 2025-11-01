//Insert element in array

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter array Index: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array Elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int in;
    cout<<"Enter Insert Number: "<<endl;
    cin>>in;
    
    for(int i=n; i>0; i--){
        arr[i]=arr[i-1];
    }
    arr[1]=in;
    cout<<"Result: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

}