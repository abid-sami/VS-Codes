//Binary Search

#include<iostream>
using namespace std;

int search(int a[], int n, int data){
    int l, r, mid;
    l=0;
    r=n-1;
    while(l<=r){
        mid=(l+r/2);
        if(data==a[mid])
        return mid;
        else if(data>a[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
        return -1;
    }
}

int main(){
    int n;
    cout<<"Enter array Index: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array Elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s;
    cout<<"Enter Search Number: "<<endl;
    cin>>s;

    int result=search(arr, n, s);
    if (result!=-1){
        cout<<"Element found at index: "<<result<< endl;
    } 
    else{
        cout<<"Element not found"<<endl;
    }

}
