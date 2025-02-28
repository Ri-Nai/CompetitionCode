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
    ll gcd(ll a, ll b)
    {
        return b ? gcd(b, a % b) : a;
    }
    void solve()
    {
        int n = rd();
        const int M = 1e5;
        vector<int> vis(M + 1);
        for (int i = 1; i <= n; ++i)
            vis[rd()] = 1;
        int ans = 0;
        for (int i = 1; i <= M; ++i)
            if (!vis[i])
            {
                int now = -1;
                for (int j = i + i; j <= M; j += i)
                {
                    if (vis[j])
                    {
                        if (now == -1)
                            now = j;
                        else
                            now = gcd(now, j);
                    }
                }
                if (now == i)
                    ++ans;
            }
        if (ans & 1)
            End("dXqwq");
        else
            End("Haitang");
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
