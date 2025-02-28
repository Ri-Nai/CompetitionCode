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
        vector<ll> A(n + 1), B(n + 1);
        vector<int> id(n + 1);
        iota(id.begin(), id.end(), 0);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        for (int i = 1; i <= n; ++i)
            B[i] = rd();
        sort(id.begin() + 1, id.end(), [&](int x, int y)
             { return A[x] < A[y]; });
        int mid = (n + 1) / 2;
        int before = n / 2 + 1;
        int after = n / 2;
        ll ans = 0;
        for (int i = 1; i < mid; ++i)
        {
            int p = id[i];
            if (B[p])
                ans = max(ans, A[p] + k + A[id[before]]);
            else
                ans = max(ans, A[p] + A[id[before]]);
        }
        for (int i = mid + 1; i <= n; ++i)
        {
            int p = id[i];
            if (B[p])
                ans = max(ans, A[p] + k + A[id[after]]);
            else
                ans = max(ans, A[p] + A[id[after]]);
        }
        int now = mid + 1;
        if (n & 1)
            now = mid - 1;
        if (B[id[mid]])
            ans = max(A[id[mid]] + k + A[id[now]], ans);
        else
            ans = max(A[id[mid]] + A[id[now]], ans);
        auto getmax = [&](int x)
        {
            int l = 0, r = 1e9, res = 0;
            auto check = [&](int limit)
            {
                int now = k;
                int cnt = 0;
                for (int i = n; i >= 1; --i)
                {
                    int p = id[i];
                    if (i == x)
                        continue;
                    if (A[p] >= limit)
                        ++cnt;
                    else if (B[p])
                    {
                        if (limit - A[p] <= now)
                            now -= limit - A[p], ++cnt;
                    }

                }
                return n - cnt <= n / 2;
            };
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (check(mid))
                    res = mid, l = mid + 1;
                else r = mid - 1;
            }
            // cout << x << ' ' << id[x] << ' ' << A[id[x]] << '\n';
            ans = max(ans, res + A[id[x]]);
        };
        for (int i = n; i >= mid; --i)
        {
            if (!B[id[i]])
            {
                getmax(i);
                break;
            }
        }
        for (int i = mid + 1; i >= 1; --i)
        {
            if (!B[id[i]])
            {
                getmax(i);
                break;
            }
        }

        for (int i = mid; i >= 1; --i)
        {
            if (!B[id[i]])
            {
                getmax(i);
                break;
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
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
