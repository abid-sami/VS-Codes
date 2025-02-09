#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x, count=0;
    cin>>n>>k;
    while(n--){
        cin>>x;
        if(x%k==0){
            count++;
        }
    }
    cout<<count;
}