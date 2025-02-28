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
        int n, k;
        const int mod = 998244353;
        scanf("%d%d", &n, &k);
        vector<pair<int, int>> seg;
        for (int i = 1; i <= n; ++i)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            seg.emplace_back(l, r);
        }
        sort(seg.begin(), seg.end());
        priority_queue<int, vector<int>, greater<int>> Q;
        ll ans = 1;
        for (auto [l, r] : seg)
        {
            while (!Q.empty() && Q.top() < l)
                Q.pop();
            ans = 1ll * ans * (k - Q.size()) % mod;
            Q.push(r);
        }
        cout << ans << endl;
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
