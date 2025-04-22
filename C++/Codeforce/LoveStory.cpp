#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        string c="codeforces";
        int count=0;
        cin>>s;
        for(int i=0; i<10; i++){
            if(s[i]!=c[i]){
                count++;
            }
        }
        cout<<count<<endl;
    }
    
}