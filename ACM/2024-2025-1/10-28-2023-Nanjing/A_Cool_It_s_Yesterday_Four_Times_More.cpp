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
    const int N = 5005;
    char s[N][N];
    void solve()
    {
        int n = rd(), m = rd();
        for (int i = 1; i <= n; ++i)
            scanf("%s", s[i] + 1);
        auto has = vector(n + 1, vector(m + 1, vector<pair<int, int>>()));
        auto mark = vector(n + 1, vector<int>(m + 1));
        auto valid = [&](int x, int y)
        {
            return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '.';
        };
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (mark[i][j] || s[i][j] == 'O')
                    continue;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                mark[i][j] = 1;
                while (!Q.empty())
                {
                    auto [x, y] = Q.front();
                    Q.pop();
                    has[i][j].emplace_back(x - i, y - j);
                    for (int k = 0; k < 4; ++k)
                    {
                        int xx = x + dx[k];
                        int yy = y + dy[k];
                        if (valid(xx, yy) && !mark[xx][yy])
                        {
                            Q.push({xx, yy});
                            mark[xx][yy] = 1;
                        }
                    }
                }
            }
        auto work = [&](int x, int y) -> int
        {
            if (has[x][y].empty())
                return 0;
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    for (auto [dx, dy] : has[x][y])
                    {
                        if (!valid(i + dx, j + dy))
                        {
                            ++cnt;
                            break;
                        }
                    }
            if (cnt < n * m - 1)
                return 0;
            return has[x][y].size();
        };
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                ans += work(i, j);
        cout << ans << '\n';
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
