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
        vector<vector<int>> edge(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        vector<int> a(n + 1);
        vector<int> notPrime(n + n + 1);
        vector<int> notPrimes;
        notPrime[1] = 1;
        for (int i = 1; i <= n + n; ++i)
        {
            if (notPrime[i])
            {
                notPrimes.push_back(i);
                continue;
            }
            for (int j = i + i; j <= n + n; j += i)
                notPrime[j] = 1;
        }
        int rt = 1;
        for (int i = 1; i <= n; ++i)
            if (edge[i].size() > edge[rt].size())
                rt = i;
        vector<int> mark(n + n + 1);
        a[rt] = n;
        mark[n] = 1;
        int tot = 0;
        auto dfs = [&](auto &&self, int u, int fa) -> void
        {
            ++tot;
            if (tot & 1)
                a[u] = n + (tot >> 1);
            else 
                a[u] = n - (tot >> 1);
            for (int v : edge[u])
            {
                if (v == fa)
                    continue;
                self(self, v, u);
            }
        };
        set<int> S;
        auto valid = [&](int x, int y)
        {
            return notPrime[abs(x - y)];
        };
        auto modify = [&](auto &&self, int u, int fa) -> void
        {
            for (int v : edge[u])
            {
                if (v == fa)
                    continue;
                if (!valid(a[u], a[v]))
                {
                    for (auto it = S.begin(); it != S.end(); ++it)
                    {
                        if (valid(*it, a[u]))
                        {
                            int t = *it;
                            S.insert(a[v]);
                            a[v] = t;
                            S.erase(a[v]);
                            break;
                        }
                    }
                }
                self(self, v, u);
            }
        };
        dfs(dfs, rt, 0);
        for (int i = 1; i <= n + n; ++i)
            S.insert(i);
        for (int i = 1; i <= n; ++i)
            S.erase(a[i]);
        modify(modify, rt, 0);
        for (int i = 1; i <= n; ++i)
            cout << a[i] << " \n"[i == n];
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
