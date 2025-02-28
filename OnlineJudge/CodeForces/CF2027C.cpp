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
        vector<ll> A(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        int S = n;
        vector<ll> need(n + 1);
        map<ll, vector<ll>> edge;
        for (int i = 1; i <= n; ++i)
        {
            // n - i + 1 = A[i]
            need[i] = A[i] + i - 1;
            edge[need[i]].push_back(need[i] + i - 1);
        }
        queue<ll> Q;
        Q.push(S);
        map<ll, int> mark;
        ll ans = n;
        while (!Q.empty())
        {
            ll u = Q.front();
            Q.pop();
            ans = max(ans, u);
            for (auto v : edge[u])
                if (!mark[v])
                    mark[v] = 1, Q.push(v);
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
