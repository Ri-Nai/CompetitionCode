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
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> A(n + 1, vector<int>(m + 1));
        vector<int> fa(n + n + 1);
        iota(fa.begin(), fa.end(), 0);
        auto find = [&](int u)
        {
            while (u != fa[u])
                u = fa[u] = fa[fa[u]];
            return u;
        };
        char *s = new char[m + 2];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", s + 1);
            for (int j = 1; j <= m; ++j)
                A[i][j] = s[j] - '0';
        }
        vector<int> link(m + 1), already(m + 1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (!A[i][j])
                    continue;
                if (already[j])
                {
                    cout << 0 << "\n";
                    return;
                }
                int &x = link[j], &y = link[m - j + 1];
                if (x)
                {
                    if (j == m - j + 1)
                    {
                        cout << 0 << "\n";
                        return;
                    }
                    fa[find(i)] = fa[find(x + n)];
                    fa[find(i + n)] = fa[find(x)];
                    already[j] = already[m - j + 1] = 1;
                }
                else if (y)
                {
                    fa[find(i + n)] = fa[find(y + n)];
                    fa[find(i)] = fa[find(y)];
                    already[j] = already[m - j + 1] = 1;
                }
                else
                    x = i;
            }
        }
        for (int i = 1; i <= n; ++i)
            if (find(i) == find(i + n))
                return cout << "0" << '\n', void();
        vector<int> mark(n + n + 1);
        for (int i = 1; i <= n + n; ++i)
            mark[find(i)] = 1;
        const int mod = 1e9 + 7;
        auto Qpow = [&](int x, int y)
        {
            int res = 1;
            for (; y; x = 1ll * x * x % mod, y >>= 1)
                if (y & 1)
                    res = 1ll * res * x % mod;
            return res;

        };
        cout << Qpow(2, accumulate(mark.begin(), mark.end(), 0) / 2) << "\n";
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
