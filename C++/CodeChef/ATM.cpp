#include <bits/stdc++.h>
using namespace std;

int main() {
	float y, i;
    int x;
	    cin>>x>>y;
	    if(x%5==0 && y>=(x+0.5)){
	        i=y-x-0.5;
	        cout<<i<<endl;
	    }
	    else{
	        cout<<y<<endl;
	    }
	

}