#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string x;
        cin>>x;
        int a=0, z=0;
        for(int i=0; i<3; i++){
            a+=x[i]-'0';
        }
        for(int i=3; i<6; i++){
            z+=x[i]-'0';
        }
        if(a==z){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}