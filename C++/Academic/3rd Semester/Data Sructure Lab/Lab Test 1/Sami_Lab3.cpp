#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter array Amount: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Product Data: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s;
    cout<<"Search Key: "<<endl;
    cin>>s;
    int pos=-1, com=0;
    for(int i=0; i<n; i++){
        com++;
        if(arr[i]==s){
            pos=i;
            break;
        }
    }
    cout<<"Searching Method: Linear Search"<<endl;
    if(pos==-1){
        cout<<"Product Code Not Found"<<endl;
    }
    else{
        cout<<"Product found at position "<<pos+1<<endl;
        cout<<"Number of comaparisons: "<<n<<endl; 
    }
    cout<<"Best case comparisons: 1"<<endl;
    cout<<"Worst case comparisons: "<<n<<endl;
}