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
        int n = rd(), m = rd();
        vector<vector<int>> edgeIn(n + 1), edgeOut(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            edgeIn[u].push_back(v);
            edgeOut[v].push_back(u);
        }
        const int inf = 1e9;
        auto bfs = [&](const vector<vector<int>> &edge)
        {
            vector<int> dep(n + 1, inf);
            queue<int> Q;
            Q.push(1);
            dep[1] = 0;
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (int v : edge[u])
                    if (dep[v] == inf)
                    {
                        dep[v] = dep[u] + 1;
                        Q.push(v);
                    }
            }
            return dep;
        };
        auto depIn = bfs(edgeIn), depOut = bfs(edgeOut);
        int ans = inf;
        for (int i = 2; i <= n; ++i)
        {
            // cout << depIn[i] << " " << depOut[i] << endl;
            ans = min(ans, depIn[i] + depOut[i]);
        }
        if (ans == inf)
            End(-1);
        End(ans);
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
