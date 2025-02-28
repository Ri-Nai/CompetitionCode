#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    queue<int> Q;
    vis[1] = 1;
    Q.push(1);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : edge[u])
            if (!vis[v])
                vis[v] = 1, Q.push(v);
    }
    if (vis[n])
        cout << "Yes" << endl;
    else cout << "No" << endl;
}
