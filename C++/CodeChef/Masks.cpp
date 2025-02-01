#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x, y, a , b;
    cin>>t;
    while(t--){
        cin>>x>>y;
        a=x*100;
        b=y*10;
        if(a>=b){
            cout<<"Cloth"<<endl;
        }
        else{
            cout<<"Disposable"<<endl;
        }
    }

}
