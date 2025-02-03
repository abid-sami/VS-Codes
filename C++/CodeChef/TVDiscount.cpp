#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, a, b, c, d, x, y;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        x=a-c;
        y=b-d;
        if(x<y){
            cout<<"first"<<endl;
        }
        else if(x>y){
            cout<<"second"<<endl;
        }
        else if(x==y){
            cout<<"any"<<endl;
        }
    }

}
