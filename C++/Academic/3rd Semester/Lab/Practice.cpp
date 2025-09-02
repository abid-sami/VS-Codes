#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n+1]; // +1 for new element
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int in, pos;
    cout << "Enter number to insert: ";
    cin >> in;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;

    for(int i=n; i>pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = in;

    cout << "Result: " << endl;
    for(int i=0; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
