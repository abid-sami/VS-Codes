#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a1[10000];
    cin >> a1;
    if (a1[0] >= 'a' && a1[0] <= 'z')
    {
            a1[0] -= 32;
        }
    cout << a1 << endl;
}
