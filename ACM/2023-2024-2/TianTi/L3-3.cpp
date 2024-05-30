#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
    {
        c = getchar();
        c == '-' && (f = -1);
    } while (!isdigit(c));
    while (isdigit(c))
    {
        res = (res << 1) + (res << 3) + (c ^ 48);
        c = getchar();
    }
    return res;
}
int main()
{
    int T = rd();
    while (T--)
    {
        cout<<1<<'\n';
    }
}
