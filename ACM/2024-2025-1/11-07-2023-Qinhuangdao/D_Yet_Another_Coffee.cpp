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
        int n, m;
        scanf("%d%d", &n, &m);
        vector<long long> cost(n + 1);
        vector<pair<int, int>> tick(m + 1);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &cost[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d%d", &tick[i].first, &tick[i].second);
        sort(tick.begin() + 1, tick.end());
        int now = 1, idx = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (cost[i] < cost[idx])
                idx = i;
            while (now <= m && tick[now].first <= i)
                cost[idx] -= tick[now++].second;
        }
        sort(cost.begin() + 1, cost.end());
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += cost[i], cout << ans << " \n"[i == n];
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
