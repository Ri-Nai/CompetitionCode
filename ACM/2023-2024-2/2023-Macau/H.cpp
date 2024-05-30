#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 998244353;
vector<int> E[N];
int n, sz[N], dep[N];
int fac[N], inv[N];
vector<int> ans[N];
int Qpow(int x, int p)
{
    int res = 1;
    for (; p; p >>= 1, x = 1ll * x * x % mod)
        if (p & 1)
            res = 1ll * res * x % mod;
    return res;
}
void Add(int &x, long long y)
{
    x = (y + x) % mod;
}
void pre()
{
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[n] = Qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
void dfs(int u)
{
    sz[u] = 1;
    for (int v : E[u])
        dep[v] = dep[u] + 1, dfs(v), sz[u] += sz[v];
    int L = 0, R = 0;
    vector<int> dp(1, 1);
    ans[u].resize(dep[u] + 1);
    for (int v : E[u])
    {
        int l = sz[v], r = sz[v] + dep[v];
        L += l, R += r;
        vector<int> tmp(R + 1);
        for (int i = R; i >= L; --i)
            for (int j = r; j >= l; --j)
                if (i - j >= 0 && i - j < dp.size())
                    Add(tmp[i], 1ll * dp[i - j] * ans[v][j - l] % mod);
        dp = tmp;
    }
    for (int i = sz[u] + dep[u]; i >= sz[u]; --i)
        for (int j = R; j >= L; --j)
            if (i - j >= 0)
                Add(ans[u][i - sz[u]], 1ll * dp[j] * inv[i - j] % mod);
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    pre();
    for (int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        E[x].push_back(i);
    }
    dfs(1);
    cout << 1ll * ans[1][0] * fac[n] % mod << '\n';
}
