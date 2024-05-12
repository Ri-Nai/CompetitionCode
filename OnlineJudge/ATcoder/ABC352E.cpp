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
        vector<pair<int, vector<int>>>op;
        vector<int> fa(n + 1), sz(n + 1, 1);
        for (int i = 1; i <= m; ++i)
        {
            vector<int> now;
            int K = rd(), C = rd();
            while (K--) now.push_back(rd());
            op.emplace_back(C, now);
        }
        sort(op.begin(), op.end());
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        auto find = [&](int u)
        {
            while(u != fa[u])
                u = fa[u] = fa[fa[u]];
            return u;
        };
        ll ans = 0;
        int now = 0;
        for (auto [x, E]:op)
        {
            set<int>S;
            for (int u : E)
                S.insert(find(u));
            ans += 1ll * (S.size() - 1) * x;
            now += S.size() - 1;
            for (auto x : S)
                fa[x] = *S.begin();
        }
        if (now == n - 1)
            cout << ans << '\n';
        else cout << -1 << '\n';
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
