#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    vector<int> cnt(n + 1, 0);
    cnt[0] = n;
    int m = 0;
    while (1)
    {
        int p = -1;
        for (int j = 0; j <= m; ++j)
            if (cnt[j] == 0)
                break;
            else
                p = j;
        if (p == -1)
            break;
        for (int j = 0; j <= p; ++j)
            --cnt[j];
        cnt[p + 1] += p + 1;
        m = max(m, p + 1);
    }
    for (int i = 0; i <= m; ++i)
        if (cnt[i])
            cout << i << ' ' << cnt[i] << '\n';
}
int main()
{
    long long n;
    cin >> n;
    if (n <= 1000)
        solve(int(n));
    else
    {
        int l = 1, r = sqrt(n) * 2, res = -1;
        auto check = [&](int m) -> bool
        {
            vector<int> cnt(m + 1);
            long long sum = m;
            long long now = 1;
            cnt[m] = m;
            for (int i = m - 1; i >= 1; --i)
            {
                long long t = (now - 1) / i + 1;
                long long p = 1ll * t * i - now;
                cnt[i] = p;
                sum += p;
                now += t;
                if (sum > n)
                    return 0;
            }
            return sum <= n;
        };
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                l = mid + 1,
                res = mid;
            else
                r = mid - 1;
        }
        int m = res;
        vector<int> cnt(m + 1);
        long long now = 1;
        n -= m;
        cnt[m] = m;
        for (int i = m - 1; i >= 1; --i)
        {
            long long t = (now - 1) / i + 1;
            long long p = 1ll * t * i - now;
            cnt[i] = p;
            n -= p;
            now += t;
        }
        cnt[0] = n;
        while (1)
        {
            int p = -1;
            for (int j = 0; j <= m; ++j)
                if (cnt[j] == 0)
                    break;
                else
                    p = j;
            if (p == -1)
                break;
            for (int j = 0; j <= p; ++j)
                --cnt[j];
            cnt[p + 1] += p + 1;
        }
        for (int i = 0; i <= m; ++i)
            if (cnt[i])
                cout << i << ' ' << cnt[i] << '\n';
    }
}
