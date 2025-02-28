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
        int n = rd(), m = rd(), k = rd();
        int w = rd();
        vector<ll> H(w + 1);
        for (int i = 1; i <= w; ++i)
            H[i] = rd();
        if (n > m)
            swap(n, m);
        priority_queue<int> Q;
        sort(H.begin() + 1, H.end());
        reverse(H.begin() + 1, H.end());
        vector<vector<int>> S(n + 2, vector<int>(m + 2));
        for (int i = 1; i <= n - k + 1; ++i)
            for (int j = 1; j <= m - k + 1; ++j)
            {
                ++S[i][j];
                --S[i][j + k];
                --S[i + k][j];
                ++S[i + k][j + k];
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1],
                Q.push(S[i][j]);
        int p = 1;
        ll res = 0;
        while (!Q.empty())
        {
            int u = Q.top();
            Q.pop();
            res += 1ll * u * H[p++];
            if (p == w + 1)
                break;
        }
        cout << res << '\n';
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
