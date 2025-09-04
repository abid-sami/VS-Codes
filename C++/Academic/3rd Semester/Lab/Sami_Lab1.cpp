#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter array Amount: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Student IDs: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s;
    cout<<"Enter Search ID: "<<endl;
    cin>>s;
    int l=0, r=n-1, m;
    bool found=0;
    while(l<=r){
        m=(l+r)/2;
        if(arr[m]==s){
            cout<<"Student ID Found at position: "<<m<<endl;
            found=1;
            break;
        }
        else if(arr[m]<s){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    if(found){
    for(int i=m; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"Student ID deleted successfully"<<endl;
    cout<<"Updated list of Student IDs: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    }
    if(!found){
        cout<<"ID not found"<<endl;
    }

}
