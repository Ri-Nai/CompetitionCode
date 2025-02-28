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
        const int mod = 998244353;
        int n = rd(), m = rd();
        auto Add = [&](int &x, int y)
        {
            x += y;
            if (x >= mod)
                x -= mod;
        };
        vector<int> choose_half(m + 1);
        vector<vector<int>> choose(m + 1, vector<int>(m + 1));
        // for (int i = 1; i <= n; ++i)
        choose[0][0] = 1;
        for (int i = 1; i <= m; ++i)
        {
            auto last = choose;
            choose.assign(m + 1, vector<int>(m + 1));
            for (int j = 0; j <= i; ++j)
                for (int k = 0; k <= i; ++k)
                {
                    if (j > 0 && k < i)
                        Add(choose[j][k], last[j - 1][k + 1]);
                    if (k > 0)
                        Add(choose[j][k], last[j][k - 1]);
                }
        }
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                Add(choose_half[i], choose[i][j]);

        // choose.assign(m + 1, vector<int>(m + 1));
        vector<int> ans(m + 1);
        ans[0] = 1;
        for (int i = 2; i <= n; ++i)
        {
            auto last = ans;
            ans.assign(m + 1, 0);
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= j; k += 2)
                    Add(ans[j], 1ll * choose_half[m / 2 - k / 2] * last[j - k] % mod);
        }
        int res = 0;
        for (int i = 0; i <= m; i += 2)
            Add(res, 1ll * ans[i] * choose_half[m / 2 - i / 2] % mod);
        cout << res <<  '\n';
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
