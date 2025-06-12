#include<iostream>
using namespace std;

int main(){
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin>>a>>b>>c;
        if(a==b){
            cout<<c<<endl;
        }
        else if(b==c){
            cout<<a<<endl;
        }
        else if(c==a){
            cout<<b<<endl;
        }
    }
}