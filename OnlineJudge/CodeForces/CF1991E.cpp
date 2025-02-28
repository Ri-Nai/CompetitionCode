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
    if (f == -1)
        exit(0);
    return res * f;
}
namespace T
{
    void solve()
    {
        int n = rd(), m = rd();
        vector<vector<int>> E(n + 1);
        vector<int> in(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            // cout << "!!!!" << u << ' ' << v << '\n';
            E[u].push_back(v);
            E[v].push_back(u);
            ++in[u], ++in[v];
        }
        vector<int> color(n + 1);
        auto dfs = [&](auto self, int u, int c) -> bool
        {
            bool flag = 0;
            // for (int v : E[u])
            // cout << u << ' ' << v << '\n';
            for (int v : E[u])
                if (color[v] && color[v] == c)
                {

                    // cout << u << ' ' << v << ' ' << c << '\n';
                    return 1;
                }
                else if (!color[v])
                {
                    flag |= self(self, v, color[v] = 3 - c);
                    if (flag)
                        return 1;
                }
            return flag;
        };
        bool flag = dfs(dfs, 1, color[1] = 1);
        if (flag == 1)
        {
            puts("Alice");
            fflush(stdout);
            for (int i = 1; i <= n; ++i)
            {
                puts("1 2");
                fflush(stdout);
                int u = rd(), v = rd();
            }
        }
        else
        {
            vector<vector<int>> has(4);
            for (int i = 1; i <= n; ++i)
            {
                // cout << "color" << i << ' ' << color[i] << '\n';
                has[color[i]].push_back(i);
            }
            puts("Bob");
            fflush(stdout);
            for (int i = 1; i <= n; ++i)
            {
                int c1 = rd(), c2 = rd();
                if ((c1 == 1 || c2 == 1) && !has[1].empty())
                {
                    printf("%d %d\n", has[1].back(), 1);
                    fflush(stdout);
                    has[1].pop_back();
                }
                else if ((c1 == 2 || c2 == 2) && !has[2].empty())
                {
                    printf("%d %d\n", has[2].back(), 2);
                    fflush(stdout);
                    has[2].pop_back();
                }
                else
                {
                    if (has[1].empty())
                    {
                        int t = 1;
                        if (c1 != 1)
                            t = c1;
                        else
                            t = c2;
                        printf("%d %d\n", has[2].back(), t);
                        has[2].pop_back();
                        fflush(stdout);
                    }
                    else if (has[2].empty())
                    {
                        int t = 2;
                        if (c1 != 2)
                            t = c1;
                        else
                            t = c2;
                        printf("%d %d\n", has[1].back(), t);
                        has[1].pop_back();
                        fflush(stdout);
                    }
                }
            }
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
