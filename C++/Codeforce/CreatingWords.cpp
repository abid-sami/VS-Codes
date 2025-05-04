#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        swap(a[0],b[0]);
        cout<<a<<" "<<b<<endl;
    }
}