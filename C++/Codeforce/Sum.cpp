#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b, c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if(a+b==c || b+c==a || a+c==b){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}