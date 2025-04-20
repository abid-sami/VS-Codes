#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, h;
    cin>>n>>h;
    int count=0;
    while(n--){
        cin>>t;
        if(t>h){
            count+=2;
        }
        else{
            count++;
        }
    }
    cout<<count<<endl;
}