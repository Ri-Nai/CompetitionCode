#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> edge(n);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y < x)
            swap(x, y);
        edge[x].push_back(y);
    }
    vector<int> color(n, -1);
    queue<int> Q;
    for (int i = 0; i < n; ++i)
    {
        if (edge[i].empty())
            continue;
        if (color[i] == -1)
        {
            for (int v : edge[i])
                if (color[v] != - 1)
                    color[i] = color[v] ^ 1;
            if (color[i] == -1)
                color[i] = 0;
        }
        for (int v : edge[i])
            if (color[v] == -1)
                color[v] = color[i] ^ 1;
    }
    for (int i = 0; i < n; ++i)
        if (color[i] != -1)
            Q.push(i);
    if (Q.empty())
        Q.push(0), color[0] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int pre = (u + 1) % n;
        int nxt = (u + n - 1) % n;
        if (color[pre] == -1)
            color[pre] = color[u] ^ 1, Q.push(pre);
        if (color[nxt] == -1)
            color[nxt] = color[u] ^ 1, Q.push(nxt);
    }
    for (int i = 0; i < n; ++i)
        putchar("BR"[color[i]]);
    puts("");
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
