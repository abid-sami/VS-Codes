#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i,n[3];
    cin>>t;
    for(i=0; i<t; i++){
        for(i=0; i<3; i++){
        cin>>n[i];
    }
    int max=n[0];
    for(i=0; i<t; i++){
        if(max<n[i]){
            max=n[i];
        }
    }
    for(i=0; i<t; i++){
        cout<<n[1]<<endl;
    }

    }
    
}