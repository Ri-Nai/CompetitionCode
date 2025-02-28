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
        int n = rd();
        vector<vector<int>> mark(n + 1, vector<int>(n + 1));
        vector<vector<int>> GCD(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
                GCD[i][j] = GCD[j][i] = gcd(i, j);
            GCD[i][i] = i;
        }
        vector<pair<int, int>> S;
        for (int i = 1; i <= n * n; ++i)
        {
            int x = rd(), y = rd();
            if (mark[x][y])
            {
                putchar('0');
                continue;
            }
            putchar('1');
            for (auto [xx, yy] : S)
            {
                if (xx == x)
                    for (int i = 1; i <= n; ++i)
                        mark[xx][i] = 1;
                else if (yy == y)
                    for (int i = 1; i <= n; ++i)
                        mark[i][yy] = 1;
                else
                {
                    int lx = xx - x, ly = yy - y;
                    int g = GCD[abs(lx)][abs(ly)];
                    lx /= g, ly /= g;
                    int tx = x, ty = y;
                    // cout << x << ' ' << y << ' ' << lx << ' ' << ly << '\n';
                    auto check = [&](int x, int y)
                    {
                        return x <= n && y <= n && x >= 1 && y >= 1;
                    };
                    while (check(tx, ty))
                    {
                        mark[tx][ty] = 1;
                        tx += lx, ty += ly;
                    }
                    tx = x, ty = y;
                    while (check(tx, ty))
                    {
                        mark[tx][ty] = 1;
                        tx -= lx, ty -= ly;
                    }
                }
            }
            S.emplace_back(x, y);
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
