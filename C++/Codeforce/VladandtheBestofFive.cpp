#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int acount=0;
        int bcount=0;
        string s;
        cin>>s;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='A'){
                acount++;
            }
            else if(s[i]=='B'){
                bcount++;
            }
        }
        if(acount>bcount){
            cout<<"A"<<endl;
        }
        else{
            cout<<"B"<<endl;
        }

    }
}