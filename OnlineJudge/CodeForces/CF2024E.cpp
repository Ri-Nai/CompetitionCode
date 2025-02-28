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
        int n = rd(), k = rd();
        struct graph
        {
            int n, k;
            vector<vector<int>> edge;
            vector<int> color, type;
            bool failed;
            graph(int _, int __) : n(_), k(__), color(n + 1, -1), edge(n + 1), type(n + 1)
            {
                input();
                failed = init();
            }
            void input()
            {
                for (int i = 1; i <= n; ++i)
                    type[i] = rd();
                int m = rd();
                for (int i = 1; i <= m; ++i)
                {
                    int u = rd(), v = rd();
                    edge[u].push_back(v);
                }
            }
            bool init()
            {
                queue<int> Q;
                color[1] = 0;
                Q.push(1);
                while (!Q.empty())
                {
                    int u = Q.front();
                    Q.pop();
                    for (int v : edge[u])
                    {
                        int nxt = (color[u] + 1) % k;
                        if (color[v] == -1)
                            color[v] = nxt, Q.push(v);
                        else if (color[v] != nxt)
                            return true;
                    }
                }
                // for (int i = 1; i <= n; ++i)
                //     cout << i << ' ' << color[i] << endl;
                for (int i = 1; i <= n; ++i)
                    if (color[i] == -1)
                        return true;
                return false;
            }
            int getCount(int x)
            {
                return count(type.begin() + 1, type.end(), x);
            }
            void change()
            {
                for (int i = 1; i <= n; ++i)
                    if (type[i])
                        color[i] = (color[i] + 1) % k;
                    else
                        color[i] = (color[i] - 1 + k) % k;
            }
            vector<ll> colorString(int inv)
            {
                vector<ll> ans(k);
                for (int i = 1; i <= n; ++i)
                {
                    int p = inv ^ type[i];
                    int x = p ? 1 : (n + 1);
                    ans[color[i]] += x;
                }
                return ans;
            }
        } from(n, k), to(n, k);
        if (from.failed || to.failed)
            End("NO");
        if (from.getCount(0) != to.getCount(1))
            End("NO");
        if (from.getCount(0) == n || from.getCount(1) == n)
            End("YES");
        from.change();
        // KMP
        auto pattern = from.colorString(0);
        auto match = to.colorString(1);
        // for (auto x : pattern)
        //     cout << x << ' ';
        // cout << endl;
        // for (auto x : match)
        //     cout << x << ' ';
        // cout << endl;
        pattern.push_back(-1);
        pattern.insert(pattern.end(), match.begin(), match.end());
        pattern.insert(pattern.end(), match.begin(), match.end());
        vector<int> Z(pattern.size());
        // cout << "here the world\n";
        for (int i = 1; i < pattern.size(); ++i)
        {
            int len = Z[i - 1];
            while (len && pattern[i] != pattern[len])
                len = Z[len - 1];
            if (pattern[i] == pattern[len])
            {
                Z[i] = len + 1;
                if (Z[i] == k)
                    End("YES");
            }
        }
        End("NO");
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
