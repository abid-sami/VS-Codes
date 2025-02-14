#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, y, z;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        int a=10*x;
        if(a<=y){
            cout<<a*z<<endl;
        }
        else{
            cout<<y*z<<endl;
        }
      
    }
}