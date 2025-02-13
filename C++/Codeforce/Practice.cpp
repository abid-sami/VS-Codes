#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a1[99999];
    cin >> a1;
    for (int i = 0; a1[i]!= '\0'; i++)
    {
        if (a1[i] >= 'A' && a1[i] <= 'Z')
        {
            a1[i] += 32;
        }
    }
    cout << a1 << endl;
}
