#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter amount of array: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s;
    cout<<"Enter search value: "<<endl;
    cin>>s;

    int l=0, r=n-1, m;
    bool found=0;
    while(l<=r){
        m=(l+r)/2;
        if(arr[m]==s){
            cout<<"Found at index: "<<m<<endl;
            found=1;
            break;
        }
        else if(arr[m]){
            
        }
    }
}