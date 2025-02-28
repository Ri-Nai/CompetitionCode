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
        int mG = rd();
        vector<vector<int>> edgeG(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= mG; ++i)
        {
            int u = rd(), v = rd();
            edgeG[u][v] = edgeG[v][u] = 1;
        }
        int mH = rd();
        vector<vector<int>> edgeH(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= mH; ++i)
        {
            int u = rd(), v = rd();
            edgeH[u][v] = edgeH[v][u] = 1;
        }
        vector<vector<int>> A(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
                A[i][j] = A[j][i] = rd();
        }
        vector<int> per(n + 1);
        iota(per.begin(), per.end(), 0);
        ll ans = 1e18;
        do
        {
            ll res = 0;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = i + 1; j <= n; ++j)
                {
                    if (edgeG[i][j] ^ edgeH[per[i]][per[j]])
                        res += A[per[i]][per[j]];
                }
            }
            ans = min(ans, res);
        }while(next_permutation(per.begin() + 1, per.end()));
        cout << ans << '\n';
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
