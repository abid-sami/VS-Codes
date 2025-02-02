#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x, y, z;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        if(x>=y && x>=z){
            cout<<"Setter"<<endl;
        }
        else if(z>=x && z>=y){
            cout<<"Editorialist"<<endl;
        }
        else if(y>=x && y>=z){
            cout<<"Tester"<<endl;
        }
    }

}
