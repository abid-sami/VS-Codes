#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        cin>>n;
        int a=n.front()-'0';
        int b=n.back()-'0';
        cout<<a+b<<endl;
    }
}