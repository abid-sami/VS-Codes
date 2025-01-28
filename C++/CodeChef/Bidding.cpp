#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, a,b,c,i;
	cin>>t;
	for(i=0; i<t; i++){
	    cin>>a>>b>>c;
	    if(a>b && a>c){
	        cout<<"Alice"<<endl;
	    }
        else if(b>a && b>c){
            cout<<"Bob"<<endl;
        }
        else if(c>a && c>b){
            cout<<"Charlie"<<endl;
        }
	}

}
