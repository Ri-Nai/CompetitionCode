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
        int n = rd(), k = rd(), q = rd();
        vector<int> A(n + 1), ans(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd() + n - i;
        vector<int> cnt(2 * n + 1);
        multiset<int> S;
        for (auto x : cnt)
            S.insert(x);
        for (int i = 1; i <= n + 1; ++i)
        {
            if (i > k)
            {
                ans[i - k] = k - *S.rbegin();
                S.erase(S.find(cnt[A[i - k]]--));
                S.insert(cnt[A[i - k]]);
            }
            if (i != n + 1)
            {
                S.erase(S.find(cnt[A[i]]++));
                S.insert(cnt[A[i]]);
            }
        }

        stack<int> stk;

        vector<vector<int>> R(n + 2, vector<int>(20));
        for (int i = 1; i <= n - k + 1; ++i)
        {
            while (!stk.empty())
            {
                int u = stk.top();
                if (ans[u] >= ans[i])
                {
                    R[u][0] = i;
                    stk.pop();
                }
                else break;
            }
            stk.push(i);
        }
        while (!stk.empty())
            R[stk.top()][0] = n - k + 2, stk.pop();
        R[n - k + 2][0] = n - k + 2;
        vector<vector<ll>> Sum(n + 2, vector<ll>(20));
        for (int i = 1; i <= n - k + 2; ++i)
        {
            Sum[i][0] = 1ll * ans[i] * (R[i][0] - i);
        }
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= n - k + 2; ++i)
            {
                R[i][j] = R[R[i][j - 1]][j - 1];
                Sum[i][j] = Sum[i][j - 1] + Sum[R[i][j - 1]][j - 1];
            }
        while (q--)
        {
            int l = rd(), r = rd() - k + 1;
            ll res = 0;
            for (int j = 19; j >= 0; --j)
            {
                if (R[l][j] <= r)
                {
                    res += Sum[l][j];
                    l = R[l][j];
                }
            }
            res += 1ll * ans[l] * (r - l + 1);
            cout << res << '\n';
        }
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
