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
        const int M = 1005;
        const int mod = 1e9 + 7;
        vector<int> P(M), Pr, id(M), lst(M);
        for (int i = 2; i < M; ++i)
        {
            if (!P[i])
                id[i] = Pr.size(), Pr.push_back(i), lst[i] = i;
            for (auto x : Pr)
            {
                int now = x * i;
                if (now >= M)
                    break;
                lst[now] = x;
                P[now] = 1;
                if (i % x == 0)
                    break;
            }
        }
        int n = rd(), m = id.size();
        vector<vector<pair<int, int>>> state(m + 1);
        for (int i = 1; i <= n; ++i)
        {
            int x = rd();
            int now = 0, pro = 1;
            bool flag = 1;
            while (x != 1)
            {
                int y = lst[x];
                int p = id[y];
                if (y > 31)
                    flag = 0, state[p + 1].emplace_back(now, pro);
                else
                {
                    if (now & 1 << p)
                        pro *= y;
                    now ^= 1 << p;
                }
                x /= y;
            }
            if (flag)
                state[0].emplace_back(now, pro);
        }
        const int PT = 1 << 11;
        vector<int> Pro(PT, 1);
        for (int i = 0; i < PT; ++i)
            for (int j = 0; j < 11; ++j)
                if (1 << j & i)
                    Pro[i] = 1ll * Pro[i] * Pr[j] % mod;
        // for (int i = 0; i <= m; ++i)
            // for (auto [p, x] : state[i])
                // cout << i << ' ' << p << ' ' << x << '\n';
        vector<vector<int>> ans(2, vector<int>(PT));
        for (auto [p, x] : state[0])
        {
            auto pre = ans[0];
            auto &now = ans[0];
            now[p] = (now[p] + x) % mod;
            for (int q = 0; q < PT; ++q)
                now[p ^ q] = (now[p ^ q] + 1ll * pre[q] * x % mod * Pro[p & q] % mod) % mod;
            // cout << p << ' ' << x << '\n';
            // for (int i = 0; i < 16; ++i)
                // cout << i << ' ' << now[i] << '\n';
            // cout << "**********\n";
            pre = now;
        }

        for (int i = 11; i < m; ++i)
        {
            for (auto [p, x] : state[i + 1])
            {
                auto pre = ans;
                ans[1][p] = (ans[1][p] + x) % mod;
                for (int q = 0; q < PT; ++q)
                {
                    ans[1][p ^ q] = (ans[1][p ^ q] + 1ll * pre[0][q] * x % mod * Pro[p & q] % mod) % mod;
                    ans[0][p ^ q] = (ans[0][p ^ q] + 1ll * pre[1][q] * x % mod * Pro[p & q] % mod * Pr[i] % mod) % mod;
                }
            }
            fill(ans[1].begin(), ans[1].end(), 0);
        }
        cout << ans[0][0] << '\n';
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
