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
const int M = 1.3e7 + 5;
typedef unsigned long long ull;
int ls[M], rs[M];
ull cnt[M], sum[M], sqr[M];
void solve()
{
    int n = rd();
    vector<vector<int>> E(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int u = rd(), v = rd();
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vector<int> id(n + 1), A(n + 1);
    for (int i = 1; i <= n; ++i)
        A[id[i] = i] = rd();
    sort(id.begin() + 1, id.end(), [&](int x, int y){return A[x] < A[y];});
    vector<int> rk(n + 1);
    for (int i = 1; i <= n; ++i)
        rk[id[i]] = i;
    int num = 0;
    vector<int> rt(n + 1);
    vector<ull> ans(n + 1);
    auto push_up = [&](int p)
    {
        cnt[p] = cnt[ls[p]] + cnt[rs[p]];
        sum[p] = sum[ls[p]] + sum[rs[p]];
        sqr[p] = sqr[ls[p]] + sqr[rs[p]];
    };
    bool flag = 0;
    auto Update = [&](auto self, int &p, int l, int r, int x, ull y) -> void
    {
        if (!p)
            p = ++num;
        if (l == r)
        {
            cnt[p] = 1;
            sum[p] = y;
            sqr[p] = y * y;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid)
            self(self, ls[p], l, mid, x, y);
        else
            self(self, rs[p], mid + 1, r, x, y);
        push_up(p);
    };
    auto Merge = [&](auto self, int &p, int q, int l, int r, ull has1, ull pre1, ull has2, ull pre2) -> ull
    {
        if (!p || !q || l == r)
        {
            ull L = has1 * sqr[q] - pre1 * sum[q];
            ull R = has2 * sqr[p] - pre2 * sum[p];
            if (!p) p = q;
            else cnt[p] += cnt[q], sum[p] += sum[q], sqr[p] += sqr[q];
            return L + R;
        }
        int mid = l + r >> 1;
        ull R = self(self, rs[p], rs[q], mid + 1, r, has1 + cnt[ls[p]], pre1 + sum[ls[p]], has2 + cnt[ls[q]], pre2 + sum[ls[q]]);
        ull L = self(self, ls[p], ls[q], l, mid, has1, pre1, has2, pre2);
        push_up(p);
        return L + R;
    };
    auto dfs = [&] (auto self, int u, int f) -> void
    {
        Update(Update, rt[u], 1, n, rk[u], A[u]);
        for (int v : E[u])
            if (v ^ f)
            {
                self(self, v, u);
                ans[u] += Merge(Merge, rt[u], rt[v], 1, 1e6, 0, 0, 0, 0);
                ans[u] += ans[v];
                flag = 0;
            }
    };
    dfs(dfs, 1, 0);
    ull res = 0;
    for (int i = 1; i <= n; ++i)
        res ^= ans[i] << 1;
    cout << res << '\n';
}
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}
/*
x * (x - y) //取最大值的一次
sz * x * x - sum * x
959 272 208 112 18 0 0 0 40 0
1130

*/
