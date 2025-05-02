#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b, c, d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        int count=0;
        if(a<b){
            count++;
        }
        if(a<c){
            count++;
        }
        if(a<d){
            count++;
        }
        cout<<count<<endl;
    }
    
}