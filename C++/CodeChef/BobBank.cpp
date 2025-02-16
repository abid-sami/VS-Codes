#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, w, x, y, z;
    cin>>t;
    while(t--){
        cin>>w>>x>>y>>z;
        cout<<w+((x*z)-(y*z))<<endl;
    }
}