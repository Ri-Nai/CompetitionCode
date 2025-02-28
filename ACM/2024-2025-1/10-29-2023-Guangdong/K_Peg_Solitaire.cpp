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
        vector<pair<int, int>> has;
        vector<vector<int>> graph(n + 3, vector<int>(m + 3, -1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                graph[i][j] = 0;
        for (int i = 1; i <= k; ++i)
        {
            int x = rd(), y = rd();
            has.emplace_back(x, y);
            graph[x][y] = 1;
        }
        typedef vector<vector<int>> Gragh;
        map<Gragh, int> mark;
        int ans = k;
        auto dfs = [&](auto &&self, int step) -> void
        {
            ans = min(ans, step);
            if (!step || mark[graph])
                return ;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                {
                    auto work = [&](int x, int y)
                    {
                        graph[x][y] ^= 1;
                        self(self, step - 1);
                        graph[x][y] ^= 1;
                    };
                    if (graph[i][j] == 1 && graph[i][j + 1] == 1)
                    {
                        graph[i][j] ^= 1;
                        graph[i][j + 1] ^= 1;
                        if (!graph[i][j + 2])
                            work(i, j + 2);
                        if (!graph[i][j - 1])
                            work(i, j - 1);
                        graph[i][j] ^= 1;
                        graph[i][j + 1] ^= 1;
                    }
                    if(graph[i][j] == 1 && graph[i + 1][j] == 1)
                    {
                        graph[i][j] ^= 1;
                        graph[i + 1][j] ^= 1;
                        if (!graph[i + 2][j])
                            work(i + 2, j);
                        if (!graph[i - 1][j])
                            work(i - 1, j);
                        graph[i][j] ^= 1;
                        graph[i + 1][j] ^= 1;
                    }
                }
        };
        dfs(dfs, k);
        cout << ans << endl;

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
