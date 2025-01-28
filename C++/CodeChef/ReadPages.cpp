#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,x,y,i;
	cin>>t;
	for(i=0; i<t; i++){
	    cin>>n>>x>>y;
        if(n<=x*y){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
	}

}
