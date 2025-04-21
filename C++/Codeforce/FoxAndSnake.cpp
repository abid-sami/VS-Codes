#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    for(int i=1; i<=a; i++){
        for(int j=0; j<b; j++){
            if(i%2==0){
                cout<<".";
            }
            if(j==(b-1)){
                cout<<"#";
            }
            else{
                cout<<".";
            }    
            
            else{
                cout<<"#";
            }
            
        }
        cout<<endl;
    } 
    
}