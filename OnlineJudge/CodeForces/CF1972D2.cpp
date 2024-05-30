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
        cin >> n >> m;
        int mx = max(n, m);
        int ans = 0;
        vector<int> lg(mx + 1);
        vector<long long> small(mx + 1);
        vector<Pr> res;
        for (int i = 2; i <= mx; ++i)
        {
            for (int j = i; j <= mx; j += i)
            {
                ll p = 1ll * (i - 1) * j;
                if (i % 2 == 0 && j % 2)
                    continue;
                if (j <= n && p <= m)
                    ++ans, res.emplace_back(j, p);
                if (i != 2 && j <= m && p <= n)
                    ++ans, res.emplace_back(p, j);
                if (p > mx)
                    break;
            }
            if (i & 1)
            {
            }
            else
            {
                lg[i] = lg[i >> 1] + 1;
                int x = 1 << lg[i];
                int y = i / x;
                if (y - x >= x)
                    small[i] = 1ll * (y - x) * y;
                else if (y - x < x)
                    small[i] = small[i >> 1] << 1;
                if (small[i])
                {
                    if (i <= n && small[i] <= m)
                        ++ans, res.emplace_back(i, small[i]);
                    if (i <= m && small[i] <= n)
                        ++ans, res.emplace_back(small[i], i);
                }
            }
        }
        cout << ans << '\n';
        sort(res.begin(), res.end());
        for (auto [x, y] : res)
            cout << x << ' ' << y << '\n';
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
