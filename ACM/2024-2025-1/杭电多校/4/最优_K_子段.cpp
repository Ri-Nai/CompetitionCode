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
    const int M = 2e5 + 5;
    vector<int> P(M), Pr;
    void init()
    {
        P[0] = P[1] = 1;
        for (int i = 2; i < M; ++i)
        {
            if (!P[i])
            {
                Pr.push_back(i);
                for (int j = i + i; j < M; j += i)
                    P[j] = 1;
            }
        }
    }
    void solve()
    {
        int n = rd(), k = rd();
        vector<int> A(n + 1), id(n + 1);
        vector<ll> sum(n + 1);
        iota(id.begin(), id.end(), 0);
        for (int i = 1; i <= n; ++i)
            A[i] = rd(), sum[i] = sum[i - 1] + A[i];
        sort(id.begin(), id.end(),
             [&](int x, int y)
             {
                 if (sum[x] == sum[y])
                     return x < y;
                 return sum[x] < sum[y];
             });
        if (n < 2 * k)
            End("impossible");
        int l = -1000 * k, r = 1000 * k, res = -1000;
        int total = 0;
        auto check = [&](int limit)
        {
            vector<int> dp(n + 1);
            const int K = 2e5;
            if (limit > K)
            {
                //[0, l]满足
                vector<int> mxpos(n + 1, -1);
                for (int i = 0, l = 0; i <= n; ++i)
                {
                    while (l <= n && sum[id[i]] - sum[id[l]] >= limit)
                        ++l;
                    for (int j = 0; j < l; ++j)
                    {
                        ++total;
                        if (id[i] - id[j] > 0 && P[id[i] - id[j]] == 0 && sum[id[i]] - sum[id[j]] >= limit)
                            mxpos[id[i]] = max(mxpos[id[i]], id[j]);
                    }
                }
                for (int i = 1; i <= n; ++i)
                {
                    ++total;
                    dp[i] = max(dp[i - 1], dp[i]);
                    if (~mxpos[i])
                        dp[i] = max(dp[mxpos[i]] + 1, dp[i]);
                    if (dp[i] >= k)
                        return 1;
                }
                return 0;
            }
            else
            {
                for (int i = 1; i <= n; ++i)
                {
                    dp[i] = max(dp[i], dp[i - 1]);
                    for (auto p : Pr)
                    {
                        if (i - p < 0)
                            break;
                        int j = i - p;
                        if (sum[i] - sum[j] >= limit)
                        {
                            dp[i] = max(dp[j] + 1, dp[i]);
                            break;
                        }
                    }
                    if (dp[i] >= k)
                        return 1;
                }
            }
            return 0;
        };
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                l = mid + 1, res = mid;
            else
                r = mid - 1;
        }
        cout << res << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // freopen("in.txt", "r", stdin);
    T::init();
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
