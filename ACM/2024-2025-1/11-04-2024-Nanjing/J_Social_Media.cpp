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
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<int> has(n + 1);
        vector<vector<int>> to(k + 1);
        vector<int> mark(k + 1);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &has[i]);
            mark[has[i]] = 1;
        }
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            to[u].push_back(v);
            to[v].push_back(u);
        }
        vector<int> cnt(k + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int u = has[i];
            for (int v : to[u])
                if (!mark[v])
                    ++cnt[v];
                else
                    ++ans;
        }
        for (int i = 1; i <= k; ++i)
            if (!mark[i])
            {
                int t = 0;
                for (int v : to[i])
                    if (i == v)
                        ++t;
                cnt[i] += t >> 1;
            }
        vector<int> diff(k + 1);
        ans >>= 1;
        // cout << ans << ' ';
        int mx = 0;

        for (int i = 1; i <= k; ++i)
            if (!mark[i])
            {
                for (int v : to[i])
                    if (!mark[v])
                        ++diff[v];
                for (int v : to[i])
                    if (v != i)
                    {
                        // cout << i << ' ' << v << ' ' << cnt[i] << ' ' << cnt[v] << endl;
                        mx = max(cnt[i] + cnt[v] + diff[v], mx);
                    }
                    else mx = max(cnt[i], mx);
                for (int v : to[i])
                    if (!mark[v])
                        --diff[v];
            }
        sort(cnt.begin(), cnt.end());
        mx = max(mx, cnt[k] + cnt[k - 1]);
        cout << ans + mx << endl;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
