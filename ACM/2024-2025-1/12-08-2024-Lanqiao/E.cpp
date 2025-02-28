#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    auto b = a;
    auto valid = [&](int x, int y)
    {
        return x >= 1 && y >= 1 && y <= m && x <= n && b[x][y];
    };
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};

    auto dfs = [&](auto &&self, int x, int y, int player) -> int
    {
        vector<int> nexts;
        b[x][y] = 0;
        // cout << x << ' ' << 
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!valid(nx, ny))
                continue;
            nexts.push_back(self(self, nx, ny, player ^ 1));
        }
        b[x][y] = a[x][y];
        if (nexts.empty())
            return b[x][y];
        if (!player)
            return *max_element(nexts.begin(), nexts.end()) + b[x][y];
        else 
            return *min_element(nexts.begin(), nexts.end()) + b[x][y];
    };
    int x, y;
    cin >> x >> y;
    cout << dfs(dfs, x, y, 0) << endl;
}
