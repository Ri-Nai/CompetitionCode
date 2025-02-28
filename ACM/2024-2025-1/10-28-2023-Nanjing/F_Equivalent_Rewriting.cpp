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
        int m = rd(), n = rd();
        vector<int> id(n + 1);
        vector<vector<int>> has(m + 1);
        for (int i = 1; i <= m; ++i)
        {
            int t = rd();
            while (t--)
            {
                int x = rd();
                has[i].push_back(x);
                id[x] = i;
            }
        }
        vector<vector<int>> edge(m + 1);
        vector<int> in(m + 1);
        for (int i = 1; i <= m; ++i)
            for (int x : has[i])
                if (id[x] != i)
                    edge[i].push_back(id[x]), ++in[id[x]];
        priority_queue<int> Q;
        for (int i = 1; i <= m; ++i)
            if (!in[i])
                Q.push(i);
        vector<int> ans;
        while (!Q.empty())
        {
            int u = Q.top();
            Q.pop();
            ans.push_back(u);
            for (int v : edge[u])
                if (--in[v] == 0)
                    Q.push(v);
        }
        vector<int> tmp(m);
        iota(tmp.begin(), tmp.end(), 1);
        if (tmp == ans)
            puts("No");
        else
        {
            puts("Yes");
            for (int x : ans)
                cout << x << ' ';
            cout << '\n';
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
