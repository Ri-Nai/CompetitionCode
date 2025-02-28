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
        int cnt = 0, valid = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ')')
                s[i] = '(';
            if (s[i] == ']')
                s[i] = '[';
            if (i && s[i] == s[i - 1])
                ++cnt;
            if (i > 1 && s[i] == s[i - 1] && s[i - 1] == s[i - 2])
                ++valid;
        }
        if (valid || cnt > 2)
            cout << "No" << '\n';
        else cout << "Yes" << '\n';

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
