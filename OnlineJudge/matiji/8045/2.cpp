#include <bits/stdc++.h>
using namespace std;
constexpr int BITLEN = 32;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    using ll = long long;
    struct XORSUM
    {
        array<int, BITLEN> cnt;
        int sz;
        XORSUM() : cnt{}, sz{} {}
        void insert(int x)
        {
            ++sz;
            for (int i = 0; i < BITLEN; ++i)
                cnt[i] += x >> i & 1;
        }
        int queryCnt(int x, int p)
        {
            int flag = x >> p & 1;
            if (flag)
                return sz - cnt[p];
            else
                return cnt[p];
        }
        ll querySum(int x)
        {
            ll res = 0;
            for (int i = 0; i < BITLEN; ++i)
                res += (1ll << i) * queryCnt(x, i);
            return res;
        }
        void XOR(int x)
        {
            for (int i = 0; i < BITLEN; ++i)
                cnt[i] = queryCnt(x, i);
        }
        XORSUM operator ^(const int &x) const
        {
            auto res = *this;
            res.XOR(x);
            return res;
        }
        void add(const XORSUM &_, int sign)
        {
            for (int i = 0; i < BITLEN; ++i)
                cnt[i] += _.cnt[i] * sign;
            sz += _.sz * sign;
        }
    };
    vector<int> sufxor(n + 1);
    vector<XORSUM> subtree(n + 1), suffix(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        sufxor[u] = sufxor[f] ^ a[u];
        

        subtree[u].insert(sufxor[u]);
        for (int v : edge[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            subtree[u].add(subtree[v], 1);
        }
    };
    dfs(dfs, 1, 0);
    ll ans = 0;
    auto dfs_ = [&](auto &&self, int u, int f) -> void
    {
        ll res = 0;
        suffix[u].XOR(a[u]);
        suffix[u].insert(a[u]);
        auto sonsuf = suffix[u];
        for (int v : edge[u])
        {
            if (v == f)
                continue;
            sonsuf.add(subtree[v] ^ sufxor[f], 1);
            res += subtree[v].querySum(sufxor[f]);
        }
        res += suffix[u].querySum(0);
        for (int v : edge[u])
        {
            if (v == f)
                continue;
            suffix[v] = sonsuf;
            suffix[v].add(subtree[v] ^ sufxor[f], -1);
            self(self, v, u);
        }
        ans = max(ans, res);
    };
    dfs_(dfs_, 1, 0);
    cout << ans << endl;
}
