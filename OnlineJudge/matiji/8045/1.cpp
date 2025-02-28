#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    auto add = [&](int x, int y)
    {
        x += y;
        if (x >= p)
            x -= p;
        return x;
    };
    vector<long long> ans(p);
    for (int i = 0; i < p; ++i)
    {
        vector<int> cnt(p);
        for (auto x : b)
        {
            int now = add(i, x);
            for (int j = now + 1; j < p; ++j)
                ans[i] += cnt[j];
            ++cnt[now];
        }
    }
    using i128 = __int128;
    i128 res = 0;
    vector<int> cnta(p), cntb(p);
    for (int x : a)
        ++cnta[x];
    for (int y : b)
        ++cntb[y];
    vector<long long> cnt(p);
    for (int x : a)
        for (int i = 0; i < p; ++i)
            cnt[add(x, i)] += cntb[i];
    for (int x : a)
    {
        res += ans[x];
        vector<long long> cntnow(p);
        for (int i = 0; i < p; ++i)
            cntnow[add(x, i)] += cntb[i];
        for (int i = 0; i < p; ++i)
            cnt[i] -= cntnow[i];
        for (int i = 0; i < p; ++i)
            for (int j = i + 1; j < p; ++j)
                res += (i128)cnt[i] * cntnow[j];
    }
    auto print = [](auto x)
    {
        string ans;
        while (x)
            ans.push_back(x % 10 + 48), x /= 10;
        if (ans.empty())
            ans.push_back('0');
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    };
    print(res);
}
