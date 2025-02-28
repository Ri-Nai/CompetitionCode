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
        int n = rd(), m = rd(), k = rd();
        vector<vector<int>> A(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &A[i][j]);
        const int dx[] = {0, 0, 1, 0};
        const int dy[] = {0, 1, 0, -1};
        auto id = [&](int x, int y)
        {
            return (x - 1) * m + y;
        };
        auto reid = [&](int p)
        {
            return make_pair((p + m - 1) / m, (p + m - 1) % m + 1);
        };
        vector<int>fa((n + 1) * m + 1);
        auto find = [&](int u)
        {
            while (u ^ fa[u])
                u = fa[u] = fa[fa[u]];
            return u;
        };
        iota(fa.begin(), fa.end(), 0);
        for (int i = 1; i <= k; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            while (x <= n)
            {
                tie(x, y) = reid(find(id(x, y)));
                if (x == n + 1)
                    break;
                int nx = x + dx[A[x][y]];
                int ny = y + dy[A[x][y]];
                A[x][y] = 2;
                fa[id(x, y)] = id(x + 1, y);
                x = nx, y = ny;
            }
            cout << y << " \n"[i == k];
        }
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
