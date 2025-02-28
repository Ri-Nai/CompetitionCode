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
        int n;
        scanf("%d", &n);
        vector<ll> cnt(n);
        map<int, int> id;
        map<int, int> mark;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            mark[x] = 1;
            id[x] = i;
            scanf("%lld", &cnt[i]);
        }
        int m;
        scanf("%d", &m);
        vector<int> need(m), total(m);
        vector<priority_queue<Pr, vector<Pr>, greater<Pr>>> rest(n);
        vector<vector<Pr>> add(m);
        queue<int> que;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &total[i]);
            for (int j = 0; j < total[i]; ++j)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                rest[id[x]].push({y, i});
            }
            int k;
            scanf("%d", &k);
            while (k--)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                add[i].emplace_back(id[x], y);
            }
        }
        auto Modify = [&](int id, int x)
        {
            cnt[id] += x;
            while (!rest[id].empty())
            {
                auto [has, queryId] = rest[id].top();
                if (has > cnt[id])
                    break;
                rest[id].pop();
                if (--total[queryId] == 0)
                    que.push(queryId);
            }
        };
        for (int i = 0; i < n; ++i)
            Modify(i, 0);
        int ans = 0;
        while (!que.empty())
        {
            ++ans;
            int queryId = que.front();
            que.pop();
            for (auto [id, x] : add[queryId])
                Modify(id, x);
        }
        cout << ans << endl;

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
