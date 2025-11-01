#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter array Amount: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Song IDs: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s;
    cout<<"Enter Song ID: "<<endl;
    cin>>s;
    int pos=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==s){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        cout<<"Not found"<<endl;
    }
    else{
    for(int i=n; i>pos+1; i--){
        arr[i]=arr[i-1];
    }
    arr[pos+1]=-1;
    n++;
    cout<<"Output: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    }
}
