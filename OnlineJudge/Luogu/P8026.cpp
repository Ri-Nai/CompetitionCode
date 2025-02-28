#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    typedef unsigned long long ull;
    void solve()
    {
        int d = rd(), n = rd(), m = rd();
        map<ull, int> cnt;
        vector<ull> res(n + 1), pw(d + 1, 1);
        vector<vector<int>> fa(d + 1, vector<int>(n + 1));
        vector<vector<vector<int>>> has(d + 1, vector<vector<int>>(n + 1));
        for (int i = 1; i <= d; ++i)
        {
            pw[i] = pw[i - 1] * 19260817;
            for (int j = 1; j <= n; ++j)
            {
                fa[i][j] = j;
                has[i][j].push_back(j);
                res[j] += j * pw[i];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += 2 * ++cnt[res[i]] - 1;
        auto find = [&](vector<int> fa, int u) -> int
        {
            while (u != fa[u])
                u = fa[u] = fa[fa[u]];
            return u;
        };
        while (m--)
        {
            int u = rd(), v = rd(), p = rd();
            u = fa[p][u], v = fa[p][v];
            if (u != v)
            {
                if (has[p][u].size() < has[p][v].size())
                    swap(u, v);
                for (int x : has[p][v])
                {
                    ans -= 2 * cnt[res[x]]-- - 1;
                    if (!cnt[res[x]])
                        cnt.erase(res[x]);
                    res[x] += (u - v) * pw[p];
                    ans += 2 * ++cnt[res[x]] - 1;
                    fa[p][x] = u;
                    has[p][u].push_back(x);
                }
            }
            cout << ans << '\n';
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
