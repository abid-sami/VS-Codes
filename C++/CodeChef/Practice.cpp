#include<iostream>
using namespace std;
int main(){
    int X,T,i;
    cin>>T;
    for(i=0; i<T; i++){
    cin>>X;
    if(X>10){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    cout<<"\n";
    }
}