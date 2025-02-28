#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
ll rd()
{
    ll res = 0, f = 1;
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
        vector<ll> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = rd();
        ll l = *min_element(A.begin(), A.end()), r = A[0], min_point = -1, max_point = -1;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            auto check = [&](ll p) -> bool
            {
                ll now = A[0] - p;
                for (int i = 1; i < n; ++i)
                {
                    if (A[i] > p)
                        now += A[i] - p;
                    else
                    {
                        if (now < p - A[i])
                            return 0;
                        now -= p - A[i];
                    }
                }
                return 1;
            };
            if (check(mid))
                min_point = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        l = A[n - 1], r = *max_element(A.begin(), A.end());
        while (l <= r)
        {
            ll mid = l + r >> 1;
            auto check = [&](ll p) -> bool
            {
                ll now = 0;
                auto B = A;
                for (int i = n - 1; i > 0; --i)
                {
                    if (B[i] < min_point)
                        B[i - 1] -= min_point - B[i], B[i] = min_point;
                }
                for (int i = 0; i < n - 1; ++i)
                {
                    if (B[i] > p)
                        B[i + 1] += B[i] - p, B[i] = p;
                }
                for (int i = 0; i < n; ++i)
                    if (B[i] > p || B[i] < min_point)
                        return 0;
                return 1;
            };
            if (check(mid))
                max_point = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        // cout << max_point << ' ' << min_point << '\n';
        cout << max_point - min_point << '\n';
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
