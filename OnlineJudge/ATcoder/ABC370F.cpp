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
        vector<int> A(n + 1), S(n + n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        for (int i = n + 1; i <= n + n; ++i)
            A[i] = A[i - n];
        for (int i = 1; i <= n + n; ++i)
            S[i] = S[i - 1] + A[i];
        auto check = [&](int limit)
        {
            vector<vector<int>> nxt(n + 1, vector<int>(20));
            for (int i = 1, r = 1; i <= n + n; ++i)
            {
                while (r <= n + n && S[r] - S[i - 1] <= limit)
                    ++r;
                nxt[i][0] = r;
            }
        };
        int l = 1, r = S[n] / k, ans = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            int now = check(mid);
            if (now)
                l = mid + 1, ans = n - now;
            else r = mid - 1;
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
