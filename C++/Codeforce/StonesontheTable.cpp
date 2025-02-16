#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, count=0;
    cin>>n;
    string c;
    cin>>c;
    for(int i=0; i<n-1; i++){
        if(c[i]==c[i+1]){
            count++;
        }
    }
    cout<<count<<endl;
    
}