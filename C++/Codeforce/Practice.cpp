#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, count = 0;
    cin >> a >> b;

    while (a <= b) {  // Keep looping until a > b
        a *= 3;  // Multiply a by 3
        b *= 2;  // Multiply b by 2
        count++; // Increase the counter
    }

    cout << count << endl;
    return 0;
}
