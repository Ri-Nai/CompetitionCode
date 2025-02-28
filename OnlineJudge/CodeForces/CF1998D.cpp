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
        vector<vector<int>> E(n + 1);
        vector<int> dis(n + 1);
        iota(dis.begin(), dis.end(), -1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
        }
        struct BIT
        {
            vector<ll> C;
            int n;
            BIT(int len) : n(len), C(len + 1) {}
            void Add(int x, int y)
            {
                while (x <= n)
                    C[x] += y, x += x & -x;
            }
            ll Sum(int x)
            {
                int res = 0;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
        } Tr(n);
        for (int i = 1; i < n; ++i)
        {
            dis[i] = min(dis[i], dis[i - 1] + 1);
            for (int v : E[i])
            {
                dis[v] = min(dis[v], dis[i] + 1);
                int l = i + 1, r = v - dis[i] - 1 - 1;
                if (l <= r)
                {
                    Tr.Add(l, 1);
                    Tr.Add(r + 1, -1);
                }
            }
        }
        for (int i = 1; i < n; ++i)
            if (Tr.Sum(i))
                putchar('0');
            else putchar('1');
        cout << '\n';
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
