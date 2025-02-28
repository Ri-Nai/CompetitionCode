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
        vector<int> A(n + 1);
        vector<int> clr(n + 1), sz(n + 1);
        int now = 0;
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        for (int i = 1; i <= n; ++i)
        {
            if (clr[i])
                continue;
            clr[i] = ++now;
            sz[now] = 1;
            int u = A[i];
            while (u != i)
            {
                ++sz[clr[u] = now];
                u = A[u];
            }
        }
        sort(sz.begin() + 1, sz.begin() + now + 1);
        int cnt = 0;
        ll ans = 0;
        for (int i = now; i >= 1; --i)
        {
            int num = sz[i];
            if (num > 4)
            {
                ans += (num - 2) / 3;
                if (num % 3 == 2)
                    ++cnt;
                else ++ans;
                // 分别削成 2, 3, 4;
            }
            else if (num == 3 || num == 4)
                ++ans;
            else if (num == 2)
            {
                if (cnt)
                    --cnt, ++ans;
                else ++cnt;
            }
        }
        if (cnt) ans += (cnt + 1) / 2;
        cout << ans << '\n';

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
