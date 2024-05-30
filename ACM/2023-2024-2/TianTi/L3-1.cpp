#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
    {
        c = getchar();
        c == '-' && (f = -1);
    } while (!isdigit(c));
    while (isdigit(c))
    {
        res = (res << 1) + (res << 3) + (c ^ 48);
        c = getchar();
    }
    return res;
}
int main()
{
    int n = rd(), m = rd();
    int Sx = 1, Sy = 1;
    const int inf = 1e9;
    vector<vector<int>> A(n + 1, vector<int>(m + 1));
    vector<vector<int>> dis(n + 1, vector<int>(m + 1, inf));
    auto mark = A;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            A[i][j] = rd();
            if (A[i][j] == 2)
                Sx = i, Sy = j;
        }
    int Q = rd();
    queue<tuple<int, int, int>> Que;
    Que.push({Sx, Sy, 0});
    dis[Sx][Sy] = 0;
    mark[Sx][Sy] = 1;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    while (!Que.empty())
    {
        auto [x, y, step] = Que.front();
        Que.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && !mark[nx][ny] && A[nx][ny] == 1)
            {
                mark[nx][ny] = 1;
                Que.push({nx, ny, dis[nx][ny] = step + 1});
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << dis[i][j] << " \n"[j == m];
    //     }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= Q; ++i)
    {
        int x = rd(), y = rd();
        ans.emplace_back(dis[y][x], i);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < Q; ++i)
    {
        bool flag = 1;
        // cout << i << ans[i].first << '\n';
        while (i + 1 < Q && ans[i + 1].first == ans[i].first)
            flag = 0, ++i;
        if (flag && ans[i].first != inf)
        {
            printf("%d %d\n", ans[i].second, ans[i].first);
            return 0;
        }
    }
    printf("No winner.\n");
}
