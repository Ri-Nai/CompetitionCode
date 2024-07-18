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
        vector<int>A(n), B(m), nxt(m);
        for (int i = 0; i < n; ++i)
            A[i] = rd();
        for (int i = 0; i < m; ++i)
            B[i] = rd();
        for (int i = 0; i < n - 1; ++i)
            A[i] = (A[i] % k - A[i + 1] % k + k) % k;
        for (int i = 0; i < m - 1; ++i)
            B[i] = (B[i + 1] % k - B[i] % k + k) % k;
        --m, --n;
        int now = 0;
        for (int i = 1; i < m; ++i)
        {
            while (now && B[i] != B[now])
                now = nxt[now - 1];
            if (B[i] == B[now])
                ++now;
            nxt[i] = now;
        }
        now = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            while (now && A[i] != B[now])
                now = nxt[now - 1];
            if (A[i] == B[now])
                ++now;
            if (now == m)
                ++ans, now = nxt[now - 1];
        }
        cout << ans << '\n';
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
