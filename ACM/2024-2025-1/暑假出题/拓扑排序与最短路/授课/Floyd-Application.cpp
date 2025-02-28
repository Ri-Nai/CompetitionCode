#include <bits/stdc++.h>
using namespace std;
void solve1()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>f(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        f[u][v] = f[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i)
        f[i][i] = 1;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                f[i][j] |= f[i][k] & f[k][i];
}
void solve2()
{
    int n, m;
    cin >> n >> m;
    const int N = 105;
    vector<bitset<N>>f(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        f[u][v] = f[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i)
        f[i][i] = 1;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            if (f[i][k])
                f[i] |= f[k];
}
int main()
{
}
