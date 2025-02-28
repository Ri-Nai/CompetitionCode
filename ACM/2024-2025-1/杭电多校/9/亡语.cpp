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
        int n = rd();
        vector<vector<pair<int, int>>> has(2);
        vector<array<int, 4>> fw;
        vector<array<int, 4>> is(n + 1);
        vector<int> H(n + 1), X(n + 1);
        vector<ll> M(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            int op = rd(), h = rd();
            if (op == 2)
            {
                int x = rd(), k = rd();
                is[i] = {op, h, x, k};
                H[i] = h, X[i] = x, M[i] = 1;
                fw.push_back({h, x, k, i});
            }
            else
            {
                is[i] = {op, h};
                has[op >> 1].emplace_back(h, i);
            }
        }
        if (is[1][0] != 1)
        {
            is[1][1] = 0;
            for (int i = 1; i <= n; ++i)
            {
                auto [op, h, x, k] = is[i];
                if (op == 2)
                {
                    if (h != 0)
                        cout << 1 << ' ' << x << ' ' << h << '\n';
                    else
                        cout << "0 0 0\n";
                }
                else
                    cout << h << '\n';
            }
            return;
        }
        ll now, multi = has[1].size() + 1;
        now = multi;
        is[1][1] = 0;
        sort(has[0].begin() + 1, has[0].end());
        sort(has[1].begin(), has[1].end());
        int lt = 1, rt = 0;
        queue<int> Q;
        priority_queue<pair<ll, int>, greater<pair<ll, int>>, vector<pair<ll, int>>> Q2;
        for (auto x : fw)
            Q2.push(make_pair(x[0], x[3]));
        for (auto [x, y] : has[0])
            Q2.push(make_pair(x, y));
        Q.push(1);
        while (!Q.empty())
        {
            int u = Q.front();
            int type = is[u][0];
            if (type == 2)
            {
                if (X[u] >= 0)
                    Q2.push(make_pair(now + H[u], u));
            }
            else if (type == 1)
            {
                vector<int> tmp;
                now += multi;
                while (!Q2.empty() && Q2.top().first <= now)
                {
                    int v = Q2.top().second;
                    tmp.push_back(v);
                    if (is[v][0] == 2)
                        H[v] *= 2, --X[v], M[v] *= is[v][3];
                    Q2.pop();
                }
                sort(tmp.begin(), tmp.end());
                for (auto x : tmp)
                    Q.push(x);
                while (rt < has[1].size() && has[1][rt].first <= now)
                    --multi, ++rt;
            }
        }
        H.assign(n + 1, 0);
        while (!Q2.empty())
        {
            int v = Q2.top().second;
            if (is[v][0] == 2)
                H[v] = Q2.top().first - now;
            Q2.pop();
        };
        for (int i = 1; i <= n; ++i)
        {
            auto [op, h, x, k] = is[i];
            if (op == 2)
            {
                if (!H[i])
                    cout << "0 0 0\n";
                else
                    cout << M[i] << ' ' << X[i] << ' ' << H[i] << '\n';
            }
            else
                cout << max(h - now, 0ll) << '\n';
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
