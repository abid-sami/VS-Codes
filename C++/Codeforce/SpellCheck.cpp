#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        int n;
        for(int i=0; i<n; i++){
            cin>>s;
        }
        
        if(s=="Timur" || s=="miurT" || s=="Trumi" || s=="mriTu"){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}