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
        vector<int> A(n + 1), sum(n + 1);
        vector<vector<int>> pre(33, vector<int>(2));
        auto suf = pre;
        auto Add = [&](vector<vector<int>> &T, int x, int p)
        {
            for (int i = 0; i < 32; ++i)
                T[i][x >> i & 1] += p;
        };
        for (int i = 1; i <= n; ++i)
            A[i] = rd(), sum[i] = sum[i - 1] ^ A[i];
        for (int i = 1; i <= n; ++i)
            Add(suf, sum[i], 1);
        Add(pre, 0, 1);
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            auto top = [&](int x)
            {
                for (int i = 31; i >= 0; --i)
                {
                    if (1 << i & x)
                        return i;
                }
                return -1;
            };
            int t = top(A[i]);
            if (t >= 0)
                ans += 1ll * suf[t][0] * pre[t][0] + 1ll * suf[t][1] * pre[t][1];
            Add(pre, sum[i], 1);
            Add(suf, sum[i], -1);
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
