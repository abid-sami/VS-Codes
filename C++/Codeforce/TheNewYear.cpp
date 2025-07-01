#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int ans=abs(a-b)+abs(b-c)+abs(c-a);
    cout<<ans/2<<endl;
}