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
        vector<vector<pair<int, int>>> E1(n + 1), E2(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd(), w = rd();
            E1[u].emplace_back(v, w);
            E2[v].emplace_back(u, w);
        }
        auto Get_Limit = [&](auto E)
        {
            vector<int> in(n + 1);
            for (int i = 1; i <= n; ++i)
                for (auto [v, w] : E[i])
                    ++in[v];
            queue<int> Q;
            for (int i = 1; i <= n; ++i)
                if (!in[i])
                    Q.push(i);
            vector<int> ans(n + 1);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (auto [v, w] : E[u])
                {
                    ans[v] = ans[u] + w;
                    if (!--in[v])
                        Q.push(v);
                }
            }
            return ans;
        };
        auto R = Get_Limit(E1), L = Get_Limit(E2);
        for (auto &x : R)
            x = n - x;
        for (auto &x : L)
            ++x;
        vector<pair<int, int>> id(n + 1);
        for (int i = 1; i <= n; ++i)
            id[i] = {R[i] - L[i] + 1, i};
        vector<int> mark(n + 1), ans(n + 1, -1);
        sort(id.begin() + 1, id.end());
        set<int> S;
        for (int i = 1; i <= n; ++i)
            S.insert(i);
        for (int i = 1; i <= n; ++i)
        {
            int pos = -1, cnt = 0;
            int x = id[i].first;
            for (int j = L[x]; j <= R[x]; ++j)
                if (!mark[j])
                    ++cnt, pos = j;
            if (cnt == 1)
            {
                mark[pos] = 1;
                ans[x] = pos;
                S.erase(x);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (mark[i])continue;
            vector<int>now;
            for (auto x : S)
            {
                if(L[x] <= i && i <= R[x])
                    now.push_back(x);
            }
            if (now.size() == 1)
                ans[now[0]] = i, S.erase(now[0]);
            else
            {
                for (auto x : now)
                    if (L[x] == R[x])
                        ans[x] = i, S.erase(x);
            }
        }
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << " \n"[i == n];
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
