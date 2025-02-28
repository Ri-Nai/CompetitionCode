#include <bits/stdc++.h>
using namespace std;
#define End() return cout << "impossible" << endl, 0
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    char *s = new char[n + 10];
    scanf("%s", s + 1);

    vector<int> val(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'R')
            val[i] = 0;
        else if (s[i] == 'G')
            val[i] = 1;
        else val[i] = 2;
    }

    vector<vector<int>> has(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int k;
        scanf("%d", &k);
        while (k--)
        {
            int x;
            scanf("%d", &x);
            has[x].push_back(i);
        }
    }
    vector<vector<pair<int, int>>> E(m + 1);
    vector<int> ops(m + 1, -1);

    for (int i = 1; i <= n; ++i)
    {
        int need = 3 - val[i];
        need %= 3;
        if (has[i].empty() && val[i] != 0)
            End();
        else if (has[i].size() == 1)
        {
            auto &should = ops[has[i][0]];
            if (should != -1 && should != need)
                End();
            should = need;
        }
        else if (has[i].size() == 2)
        {
            int u = has[i][0], v = has[i][1];
            E[u].emplace_back(v, need);
            E[v].emplace_back(u, need);
        }
    }

    int ans = 0;
    vector<int> mark(m + 1);
    vector<int> tmp_op(m + 1);
    auto get_ans = [&](int S)
    {
        vector<int> seq;
        queue<int> Q;
        int tot = 0;

        mark[S] = ++tot;
        Q.push(S);
        while (!Q.empty())
        {
            int u = Q.front();
            seq.push_back(u);
            Q.pop();
            for (auto [v, w] : E[u])
            {
                if (!mark[v])
                {
                    mark[v] = ++tot;
                    Q.push(v);
                }
            }
        }

        int ans = -1;
        auto get_ = [&](int initial)
        {
            tmp_op[S] = initial;
            int res = 0;
            for (auto u : seq)
            {
                if (ops[u] != -1 && tmp_op[u] != ops[u])
                    return -1;
                for (auto [v, w] : E[u])
                {
                    if (ops[v] != -1 && (tmp_op[u] + ops[v]) % 3 != w)
                        return -1;
                    if (mark[v] < mark[u] && (tmp_op[u] + tmp_op[v]) % 3 != w)
                        return -1;
                    tmp_op[v] = (3 + w - tmp_op[u]) % 3;
                }
                res += tmp_op[u];
            }
            return res;
        };

        for (int now : {0, 1, 2})
        {
            int res = get_(now);
            if (res != -1 && (ans == -1 || ans > res))
                ans = res;
        }
        return ans;
    };
    for (int i = 1; i <= m; ++i)
    {
        if (!mark[i])
        {
            int res = get_ans(i);
            if (res == -1)
                End();
            ans += res;
        }
    }
    cout << ans << endl;
}
