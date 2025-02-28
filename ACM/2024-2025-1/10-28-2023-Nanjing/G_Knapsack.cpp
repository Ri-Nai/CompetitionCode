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
        int n = rd(), W = rd(), k = rd();
        vector<pair<int, int>> item;
        for (int i = 1; i <= n; ++i)
        {
            int u = rd(), v = rd();
            item.emplace_back(u, v);
        }
        sort(item.begin(), item.end());
        reverse(item.begin(), item.end());
        priority_queue<int, vector<int>, greater<int>> Q;
        ll now = 0;
        vector<ll> has;
        for (auto [w, v] : item)
        {
            has.push_back(now);
            now += v;
            Q.push(v);
            if (Q.size() > k)
                now -= Q.top(), Q.pop();
        }
        ll ans = now;
        vector<ll> dp(W + 1);
        for (int i = item.size() - 1; i >= 0; --i)
        {
            auto [w, v] = item[i];
            for (int j = W; j >= w; --j)
                dp[j] = max(dp[j], dp[j - w] + v);
            ans = max(ans, dp[W] + has[i]);
        }
        cout << ans << '\n';
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
