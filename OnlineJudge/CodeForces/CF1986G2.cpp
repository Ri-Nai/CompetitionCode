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
    const int M = 5e5 + 5;
    vector<vector<int>> divs(M);
    void init()
    {
        for (int i = 1; i < M; ++i)
            for (int j = i; j < M; j += i)
                divs[j].push_back(i);
    }
    void solve()
    {
        int n = rd();
        long long ans = 0;
        vector<int> P(n + 1);
        vector<int> need(n + 1), has(n + 1);
        vector<vector<int>> need_id(n + 1), has_id(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            P[i] = rd();
            need[i] = i / gcd(i, P[i]);
            has[i] = P[i] / gcd(i, P[i]);

            need_id[need[i]].push_back(i);
            has_id[has[i]].push_back(i);
            // has[i] % need[j] = 0, has[j] % need[i] = 0
            if (need[i] == 1)
                --ans;
        }
        // cout << " ?" << '\n';
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int res = 0;
            for (int j = i; j <= n; j += i)
                for (int id : has_id[j])
                    ++cnt[need[id]];
            for (int id : need_id[i])
                for (int div : divs[has[id]])
                    ans += cnt[div];
            for (int j = i; j <= n; j += i)
                for (int id : has_id[j])
                    --cnt[need[id]];
            // cout << res << ' ';
        }
        ans >>= 1;
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    T::init();
    int t; cin >> t; while(t--)
    T::solve();
}
/*
2 4 1 3 5
1 1 1 3 5
2 4 1 1 1
如果是
1的倍数的话
*/
