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

void solve()
{
    int n = rd();
    vector<int> A(2 * n + 6);
    vector<int> L(n + 1), R(2 * n + 2);
    for (int i = 1; i <= 2 * n; ++i)
        A[i] = rd();
    vector<int> ans(2 * n + 6, -1);
    auto Solve = [&](auto self, int l, int r, int x) -> int
    {
        if (ans[l] != -1)
            return ans[l];
        // cout << l << ' ' << r << ' ' << x << '\n';
        vector<int> dp(2 * n + 6);
        for (int i = l + 1; i <= r; ++i)
        {
            dp[i] = max(dp[i], dp[i - 1] + x);
            if (i != r && R[i] != -1 && R[i] < r)
            {
                int res = self(self, i, R[i], A[i]);
                dp[R[i]] = max(dp[R[i]], dp[i] + res);
            }
        }
        return (ans[l] = dp[r]);
    };
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (!L[A[i]])
            L[A[i]] = i;
        else
            R[L[A[i]]] = i + 1;
    }
    cout << Solve(Solve, 0, 2 * n + 2, 0) << '\n';
}
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    solve();
}
