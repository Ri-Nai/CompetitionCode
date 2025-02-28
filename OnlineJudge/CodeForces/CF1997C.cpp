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
        int n;
        cin >> n;
        vector<int> A(n);
        map<int, int> cnt;
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            ++cnt[A[i]];
        }
        int m;
        cin >> m;
        auto solve = [&]()
        {
            string s;
            cin >> s;
            int t = s.size();
            // cout << t << ' ' << s << '\n';
            if (t != n)
                End("NO");
            vector<int> has(26), is(26, 1e9 + 1);
            for (int i = 0; i < n; ++i)
            {
                // cout << i << ' ';
                int c = s[i] - 'a';
                if (is[c] == 1e9 + 1)
                    is[c] = A[i];
                else if (A[i] != is[c])
                    End("NO");
                ++has[c];
            }
            for (int i = 0; i < n; ++i)
            {
                int c = s[i] - 'a';
                if (cnt[is[c]] != has[c])
                    End("NO");
            }
            End("YES");
        };
        for (int i = 1; i <= m; ++i)
            solve();
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
