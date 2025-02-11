#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(x>=y){
            cout<<y<<endl;
        }
        else{
            cout<<x<<endl;
        }
    }
}