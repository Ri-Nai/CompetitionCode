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
        int n;
        scanf("%d", &n);
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &A[i]);
        auto f = vector(n, vector<int>(n));
        const int inf = 1e9;
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                scanf("%d", &f[i][j]);
            ans += 1ll * (A[i] - 1) * *min_element(f[i].begin(), f[i].end());
        }
        vector<int> dis(n + 1, inf);
        dis[0] = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; ++i)
        {
            int u = n;
            for (int j = 0; j < n; ++j)
                if (!vis[j] && dis[j] < dis[u])
                    u = j;
            ans += dis[u];
            vis[u] = 1;
            for (int j = 0; j < n; ++j)
                dis[j] = min(dis[j], f[u][j]);
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
