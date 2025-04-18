#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t, a;
    cin>>t;
    int count=0;
    for(int i=0; i<t; i++){
        cin>>a;
        count+=a;
    }
        if(count>=1){
            cout<<"Hard"<<endl;
        }
        else{
            cout<<"Easy"<<endl;
        }
}