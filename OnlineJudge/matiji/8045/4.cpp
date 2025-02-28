#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));
    vector<pair<int, int>> base;
    vector<int> mx(n + 1);
    auto points = graph;
    for (int i = 1; i <= k; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2), swap(y1, y2);
        auto sign = [](auto x) {return x / abs(x);};
        int dx = sign(x2 - x1);
        int dy = sign(y2 - y1);
        for (int t = 0; t <= x2 - x1; ++t)
        {
            graph[x1 + dx * t][y1 + dy * t] = 1;
            mx[y1 + dy * t] = max(mx[y1 + dy * t], x1 + dx * t);
        }

        base.emplace_back(x1 - dx, y1 - dy);
        base.emplace_back(x2 + dx, y2 + dy);
    }
    base.emplace_back(1, 1);
    base.emplace_back(n, n);
    auto check = [&](int x, int y)
    {
        return x <= n && y <= n && x >= 1 && y >= 1 && graph[x][y] == 0;
    };
    for (auto [x, y] : base)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (check(x, i))
                points[x][i] = 1;
            if (check(i, y))
                points[i][y] = 1;
        }
    }
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    int tot = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (graph[i][j])
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (check(nx, ny))
                        points[nx][ny] = 1;
                    nx += dx[k];
                    ny += dy[k];
                    if (check(nx, ny))
                        points[nx][ny] = 1;
                }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (points[i][j])
                points[i][j] = ++tot;
    auto bfs = [&](int S)
    {
        if (!check(1, S))
            return;
        queue<array<int, 3>> Q;
        Q.push({1, S, 1});
        vector<int> vis(tot + 1);
        vis[points[1][S]] = 1;
        auto isPoint = [&](int x, int y)
        {
            return check(x, y) && points[x][y] && !vis[points[x][y]];
        };
        
        while (!Q.empty())
        {
            auto [x, y, step] = Q.front();
            Q.pop();
            if (x > mx[y])
            {
                int &res = ans[S][y];
                if (res == -1)
                    res = step + n - x;
                else 
                    res = min(res, step + n - x);
            }
            for (int i = 0; i < 4; ++i)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (check(xx, yy) && isPoint(xx, yy))
                    Q.push({xx, yy, step + 1}), vis[points[xx][yy]] = 1;
            }
        }
    };
    for (int i = 1; i <= n; ++i)
        bfs(i);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
}

