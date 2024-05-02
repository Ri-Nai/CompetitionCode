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
        vector<int> A(n + 1), B(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        for (int i = 1; i <= n; ++i)
            B[i] = rd();
        vector<pair<int, int>>C;
        ll now = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (A[i] < B[i])
                C.emplace_back(A[i], B[i]), now += B[i] - A[i];
        }
        auto cmp1 = [&] (Pr a, Pr b)
        {
            return a.second > b.second;
        };
        sort(C.begin(),C.end(),cmp1);
        if (k > C.size())
        {
            cout << 0 << '\n';
            return ;
        }
        multiset<int>S;
        for (int i = 0; i < k; ++i)
        {
            S.insert(C[i].first);
            // cout << C[i].second << ' ';
            now -= C[i].second;
        }
        ll ans = now;
        // cout << '\n';
        // cout << now << '\n';
        // cout << C.size() << ' ' << S.size() << '\n';
        if (k != 0)
        {

            for (int i = k; i < C.size(); ++i)
            {
                auto it = S.end();
                --it;
                now += *it;
                now -= C[i].second;
                ans = max(ans, now);
                S.erase(it);
                S.insert(C[i].first);
            }
        }
        cout << max(0ll, ans) << '\n';

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
