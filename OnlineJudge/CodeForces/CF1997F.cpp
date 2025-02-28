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
        vector<pair<int, int>> E;
        for (int i = 0; i < n; ++i)
        {
            int x = rd(), y = rd();
            if (x > y)
                swap(x, y);
            E.emplace_back(x, y);
        }
        vector<int> ans(k + 1, 1e9);
        ans[0] = 0;
        for (auto [x, y] : E)
        {
            int p = 0;
            int t = 0;
            vector<pair<int, int>> Q;
            for (int i = 1; i <= y - x; ++i)
            {
                t += x;
                Q.push_back({++p, t});
            }
            for (int i = 1; i <= x; ++i)
            {
                t += x - i + 1;
                Q.push_back({++p, t});
                t += x - i;
                Q.push_back({++p, t});
            }
            for (int p = k; p >= 0; --p)
            {
                for (auto [val, ops] : Q)
                    ans[p] = min(ans[max(p - val, 0)] + ops, ans[p]);
            }
        }
        if (ans[k] == 1e9)
            End("-1");
        cout << ans[k] << '\n';
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
