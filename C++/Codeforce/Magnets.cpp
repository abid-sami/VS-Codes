#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, count=0;
    string a, b;
    cin>>t;
    while(t--){
        cin>>b;
        if(a!=b){
        count++;
        a=b;
        }
    }
    cout<<count<<endl;
}