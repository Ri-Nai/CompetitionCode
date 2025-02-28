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
        int n = rd(), m = rd();
        vector<vector<int>> has(n + 1, vector<int>(11));
        for (int i = 1; i <= m; ++i)
        {
            int p = rd(), d = rd(), k = rd();
            has[p][d] = max(has[p][d], k);
        }
        vector<int> fa(n + 1);
        auto find = [&](int u)
        {
            while (u ^ fa[u])
                u = fa[u] = fa[fa[u]];
            return u;
        };
        iota(fa.begin(), fa.end(), 0);
        for (int i = 1; i <= 10; ++i)
        {
            vector<int> mark(n + 1);
            for (int j = 1; j <= n; ++j)
            {
                if (mark[j])
                    continue;
                int total = has[j][i];
                if (!total)
                    continue;
                for (int k = j; total >= 0 && k <= n; k += i)
                {
                    total = max(has[k][i], total);
                    --total;
                    mark[k] = 1;
                    fa[find(k)] = find(j);
                }
            }
        }
        vector<int> mark(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (!mark[find(i)])
                ++ans, mark[find(i)] = 1;
        cout << ans << '\n';
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
