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
        vector<vector<int>> A(n + 2, vector<int>(n + 2, 1));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                A[i][j] = rd();
        vector<vector<int>> vis(n + 1, vector<int>(n + 1));
        vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));
        vector<vector<vector<Pr>>> E(n + 1, vector<vector<Pr>>(n + 1));
        vis[1][1] = 1;
        ans[1][1] = 0;
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, -1, 0, 1};
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    // cout << i << ' ' << j << '\n';
                    if (!A[nx][ny])
                    {
                        E[i][j].emplace_back(nx, ny);
                        continue;
                    }
                    // cout << "Here" << '\n';
                    int Dx = -dx[k], Dy = -dy[k];
                    int x = i, y = j;
                    while (!A[x + Dx][y + Dy])
                        x += Dx, y += Dy;
                    E[i][j].emplace_back(x, y);
                }
            }
        }
        queue<pair<int, int>> Q;
        Q.push({1, 1});
        while (!Q.empty())
        {
            auto [x, y] = Q.front();
            Q.pop();
            for (auto [nx, ny] : E[x][y])
            {
                auto pd = [&](int x, int y)
                {
                    return x <= n && y <= n && x >= 1 && y >= 1;
                };
                if (!pd(nx, ny) || vis[nx][ny] || A[nx][ny])
                    continue;
                Q.push({nx, ny});
                vis[nx][ny] = 1;
                ans[nx][ny] = ans[x][y] + 1;
            }
        }
        cout << ans[n][n] << '\n';
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
