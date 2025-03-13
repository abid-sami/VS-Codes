#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    string s;
    while (x--)
    {
        cin >> s;
        if (s == "YES" || s == "yes" || s == "Yes" || s == "YeS" || s == "yES" || s == "yEs")
        {
            cout << "YES" << endl;

        }
        else
        {
            cout << "NO" << endl;

        }
    }
}