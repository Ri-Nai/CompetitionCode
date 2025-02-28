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
        vector<pair<int, int>> P;
        for (int i = 1; i <= n; ++i)
            P.emplace_back(A[i], B[i]);
        sort(P.begin(), P.end());
        priority_queue<int> Q;
        ll sum = 0;
        for (int i = 0; i < k - 1; ++i)
        {
            Q.push(P[i].second);
            sum += P[i].second;
        }
        ll ans = 1e18;
        for (int i = k - 1; i < n; ++i)
        {
            auto [x, y] = P[i];
            sum += y;
            // cout << sum << ' ' << x << endl;
            ans = min(ans, 1ll * x * sum);
            Q.push(y);
            sum -= Q.top();
            Q.pop();
        }
        cout << ans << endl;
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
