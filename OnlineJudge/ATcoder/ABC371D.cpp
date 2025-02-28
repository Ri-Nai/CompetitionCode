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
        vector<int> X(n + 1), P(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd();
        for (int i = 1; i <= n; ++i)
            P[i] = rd();
        auto Y = X;
        sort(Y.begin() + 1, Y.end());
        auto it = unique(Y.begin() + 1, Y.end());
        Y.erase(it, Y.end());
        int m = Y.size() - 1;
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; ++i)
            pos[i] = lower_bound(Y.begin() + 1, Y.end(), X[i]) - Y.begin();
        vector<ll> sum(m + 1);
        for (int i = 1; i <= n; ++i)
            sum[pos[i]] += P[i];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        int Q = rd();
        while (Q--)
        {
            int l = rd(), r = rd();
            int pl = lower_bound(Y.begin() + 1, Y.end(), l) - Y.begin() - 1;
            int pr = upper_bound(Y.begin() + 1, Y.end(), r) - Y.begin() - 1;
            // cout << pl << ' ' << pr << '\n';
            cout << sum[pr] - sum[pl] << '\n';
        }


    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
