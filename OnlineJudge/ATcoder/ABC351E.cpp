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
        vector<vector<int>> X(2), Y(2);
        for (int i = 0; i < n; ++i)
        {
            int x = rd(), y = rd();
            int p = x + y & 1;
            X[p].push_back(x + y);
            Y[p].push_back(x - y);
        }
        ll ans = 0;
        for (int i = 0; i < 2; ++i)
        {
            sort(X[i].begin(), X[i].end());
            sort(Y[i].begin(), Y[i].end());
            int m = X[i].size();
            for (int j = 0; j < m; ++j)
            {
                ll x = 1ll * j * X[i][j] + 1ll * (m - j - 1) * -X[i][j];
                ll y = 1ll * j * Y[i][j] + 1ll * (m - j - 1) * -Y[i][j];
                ans += (x + y) / 2;
            }
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
