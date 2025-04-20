#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b;
    int count=0;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(b-a>=2){
            count++;
        }
    }
    cout<<count<<endl;
}