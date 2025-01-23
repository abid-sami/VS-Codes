#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, x, y;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>x>>y;
        if(x>y){
            cout<<"Loss"<<endl;
        }
        else if(x<y){
            cout<<"Profit"<<endl;
        }
        else{
            cout<<"Neutral"<<endl;
        }
        
    }
}