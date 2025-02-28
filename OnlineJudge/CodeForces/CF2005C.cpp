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
        // int n = rd(), m = rd();
        int n, m;
        cin >> n >> m;
        vector<string> S(n + 1);
        vector<vector<int>> ans(n + 1, vector<int>(5, -1e9));
        for (int i = 1; i <= n; ++i)
            cin >> S[i];
        ans[0][0] = 0;
        auto get_id = [&](char c)
        {
            if (c == 'n')
                return 0;
            if (c == 'a')
                return 1;
            if (c == 'r')
                return 2;
            if (c == 'e')
                return 3;
            if (c == 'k')
                return 4;
            return -1;
        };
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                // 从 j 开始
                int now = j;
                int cnt = 0;
                int tot = 0;
                for (int k = 0; k < m; ++k)
                {
                    int id = get_id(S[i][k]);
                    if (id == -1)
                        continue;
                    if (id == now)
                        now = (now + 1) % 5, ++cnt;
                    ++tot;
                }
                ans[i][now] = max(ans[i][now], ans[i - 1][j] + cnt - (tot - cnt));
            }
            for (int j = 0; j < 5; ++j)
            {
                ans[i][j] = max(ans[i][j], ans[i - 1][j]);
                res = max(res, ans[i][j] - j * 2);
                // nrrareknkarekz
                // n  arekn arek
                //  __     _    _
            }
        }
        cout << res << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
