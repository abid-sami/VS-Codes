#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a1[100];
    int small = 0, big = 0;
    cin >> a1;
    for (int i = 0; a1[i] != '\0'; i++)
    {
        if (a1[i] >= 'A' && a1[i] <= 'Z')
        {
            big++;
        }
        else if (a1[i] >= 'a' && a1[i] <= 'z')
        {
            small++;
        }
    }
    for (int i = 0; a1[i] != '\0'; i++)
    {
        if (big <= small)
        {
            if (a1[i] >= 'A' && a1[i] <= 'Z')
            {
                a1[i] += 32;
            }
        }
        else
        {
            if (a1[i] >= 'a' && a1[i] <= 'z')
                a1[i] -= 32;
        }
    }
    cout << a1 << endl;
}
