#include<iostream>
using namespace std;
int main() {
    int k,n,w;
    cin>>k>>n>>w;
    int total=0;
    for(int i=1;i<=w;i++) {
        total+=k*i;
    }
    if(total>n) {
        cout<<total-n<<endl;
    }
    else {
        cout<<0<<endl;
    }
}