#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
        (c = getchar()) == '-' && (f = -1);
    while (!isdigit(c));
    while (isdigit(c))
        res = (c ^ 48) + (res << 1) + (res << 3), c = getchar();
    return res * f;
}
namespace T
{
    void solve()
    {
        int n = rd();
        vector<int> color(n + 1);
        if (n <= 6)
        {
            color = {0, 1, 2, 2, 3, 3, 4};
            cout << color[n] << '\n';
            for (int i = 1; i <= n; ++i)
                cout << color[i] << ' ';
            cout << '\n';
            return;
        }
        cout << 4 << '\n';
        for (int i = 1; i <= n; ++i)
            cout << (i & 3) + 1 << ' ';
        cout << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
/*
100
011
010
001
000

^ 2
^ 5
^ 7

*/
