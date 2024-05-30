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
        vector<int> P(n + 1);
        for (int i = 1; i <= n; ++i)
            P[i] = rd();
        auto get = [&] (int p) -> vector<int>
        {
            vector<Pr> Big;
            vector<bool> mark(n + 1);
            vector<int> Small(1, p ? n : 1);
            vector<int> ans(n + 1);
            set<int> S;
            // cout << "****" << p << '\n';
            for (int i = 1; i <= n; ++i)
                S.insert(i);
            for (int i = 2; i < n; i += 2)
            {
                Big.emplace_back(P[i + p], i + p), Small.push_back(i + (p ^ 1));
            }
            sort(Big.begin(), Big.end());
            for (auto [y, x] : Big)
            {
                // cout << x << ' ' << y << '\n';
                // cout << S.size() << '\n';
                // cout << "*****\n";
                // cout << "*****\n";
                mark[x] = 1;
                ans[x] = *S.rbegin();
                // cout << ans[x] << '\n';
                S.erase(ans[x]);
            }
            for (auto x : Small)
            {
                int now = 1e9;
                if (x > 1 && mark[x - 1]) now = min(now, ans[x - 1] + P[x - 1]);
                if (x < n && mark[x + 1]) now = min(now, ans[x + 1] + P[x + 1]);
                // cout << x << ' ' << now << ' ' << now - P[x] << '\n';
                auto it = S.lower_bound(now - P[x]);
                if (it == S.begin())
                    return {};
                --it;
                ans[x] = *it;
                S.erase(it);
            }
            ans[p ? 1 : n] = *S.begin();
            return ans;
        };
        auto res = get(0);
        if (res.empty())
            res = get(1);
        // cout << "*******\n";
        for (int i = 1; i <= n; ++i)
            cout << res[i] << " \n"[i == n];
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
/*
8
1 2 4 5 7 6 8 3
  8   7 5 6
*/
