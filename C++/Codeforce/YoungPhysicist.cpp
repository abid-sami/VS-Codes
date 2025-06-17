#include<iostream>
using namespace std;

int main(){
    int t,x,y,z, xs=0,ys=0,zs=0;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        xs+=x;
        ys+=y;
        zs+=z;
    }
    if(xs==0 && ys==0 && zs==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}