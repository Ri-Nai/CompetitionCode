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
        vector<vector<pair<int, int>>> E((n + 1) << 2);
        auto Ins = [&](auto self, int l, int r, int L, int R, int p, auto edge) -> void
        {
            if (l == L && R == r)
            {
                E[p].push_back(edge);
                return;
            }
            int mid = L + R >> 1;
            if (r <= mid)
                self(self, l, r, L, mid, p << 1, edge);
            else if (l > mid)
                self(self, l, r, mid + 1, R, p << 1 | 1, edge);
            else
                self(self, l, mid, L, mid, p << 1, edge),
                self(self, mid + 1, r, mid + 1, R, p << 1 | 1, edge);
        };
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd(), l = rd(), r = rd();
            Ins(Ins, l, r, 1, n, 1, make_pair(u, v));
        }
        struct DSU
        {
            int n;
            vector<int> fa, sz;
            vector<ll> tag;
            stack<int> stk;
            DSU(int size) : n(size), fa(n + 1), sz(n + 1, 1), tag(n + 1, 0)
            {
                iota(fa.begin(), fa.end(), 0);
            }
            int find(int u)
            {
                while (u ^ fa[u])
                    u = fa[u];
                return u;
            }
            void Merge(int u, int v)
            {
                u = find(u), v = find(v);
                if (u == v)
                    return ;
                if (sz[u] < sz[v])
                    swap(u, v);
                assert(u <= n);
                assert(v <= n);
                fa[v] = u;
                tag[v] -= tag[u];
                sz[u] += sz[v];
                stk.push(v);
            }
            void roll_back(int state)
            {
                while (stk.size() != state)
                {
                    int v = stk.top();
                    stk.pop();
                    int u = fa[v];
                    assert(u <= n);
                    assert(v <= n);
                    fa[v] = v;
                    tag[v] += tag[u];
                    sz[u] -= sz[v];
                }
            }
            int get_state() { return stk.size(); }
            void Update(int x) { tag[find(1)] += x; }
        } D(n);
        auto work = [&](auto self, int L, int R, int p) -> void
        {
            int now = D.get_state();
            assert(p <= (n << 2));
            for (auto [u, v] : E[p])
                D.Merge(u, v);
            if (L == R)
                D.Update(R);
            else
            {
                int mid = L + R >> 1;
                self(self, L, mid, p << 1);
                self(self, mid + 1, R, p << 1 | 1);
            }
            D.roll_back(now);
        };
        work(work, 1, n, 1);
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            ans ^= D.tag[i];
        cout << ans << '\n';
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
