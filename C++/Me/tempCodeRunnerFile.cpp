#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin>>a>>b;
    int n=a.length();
    for(int i=0; i<n; i++){
        if(a[i]!=b[n-1-i]){
            cout<<"NO"<<endl;
            break;
        }
        else{
            cout<<"YES"<<endl;
            break;
        }
    }
    
}
