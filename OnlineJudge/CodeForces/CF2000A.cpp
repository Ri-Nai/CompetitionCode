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
            string s;
            cin >> s;
            if (s.size() <= 2)
                End("NO");
            if (s[0] != '1' || s[1] != '0')
                End("NO");
            if (s.size() == 3 && (s[2] == '1' || s[2] == '0'))
                End("NO");
            if (s[2] == '0')
                End("NO");
            End("YES");
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
