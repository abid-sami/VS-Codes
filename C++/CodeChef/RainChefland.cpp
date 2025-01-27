#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x, i;
    cin>>t;
    for(i=0; i<t; i++){
        cin>>x;
        if(x<3){
            cout<<"Light"<<endl;
        }
        else if(x>=3 && x<7){
            cout<<"Moderate"<<endl;
        }
        else if(x>=7){
            cout<<"Heavy"<<endl;
        }
    }
}
