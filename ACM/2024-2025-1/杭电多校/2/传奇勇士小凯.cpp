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
    ll gcd(ll x, ll y)
    {
        return y ? gcd(y, x % y) : x;
    }
    void solve()
    {
        int n = rd();
        vector<ll> P(n + 1);
        vector<ll> dpf(n + 1, 0), dpg(n + 1, 1);
        vector<vector<int>> E(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
            P[i] = rd();
        auto dfs = [&](auto self, int u, int f) -> void
        {
            ll maxf = 0, maxg = 1;
            for (int v : E[u])
            {
                if (v == f)
                    continue;
                self(self, v, u);
                if (dpf[v] * maxg > dpg[v] * maxf)
                    maxf = dpf[v], maxg = dpg[v];
            }
            ll g = maxg / gcd(maxg, P[u]) * P[u];
            dpf[u] = g / maxg * maxf + g / P[u] * 15;
            dpg[u] = g;
            g = gcd(dpf[u], dpg[u]);
            dpf[u] /= g;
            dpg[u] /= g;
        };
        dfs(dfs, 1, 0);
        cout << dpf[1] << '/' << dpg[1] << '\n';
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
/*
    n = int(input())
    Edge = [[] for i in range(n + 1)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        Edge[u].append(v)
        Edge[v].append(u)
    p = [0] + list(map(int, input().split()))
    dpf = [0] * (n + 1)
    dpg = [1] * (n + 1)
    def gcd(a, b):
        if b == 0:
            return a
        return gcd(b, a % b)
    def dfs(u, f):
        maxf = 0
        maxg = 1
        for v in Edge[u]:
            if v == f:
                continue
            dfs(v, u)
            if dpf[v] * maxg > dpg[v] * maxf:
                maxf = dpf[v]
                maxg = dpg[v]
        g = maxg // gcd(maxg, p[u]) * p[u]
        dpf[u] = g // maxg * maxf + g // p[u] * 15
        dpg[u] = g
        g = gcd(dpf[u], dpg[u])
        dpf[u] //= g
        dpg[u] //= g
    dfs(1, 0)
    print(dpf[1], dpg[1], sep = '/')
*/
