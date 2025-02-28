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
        vector<int> A(n + 1);
        vector<vector<int>> has(n + 1);
        for (int i = 1; i <= n; ++i)
            has[A[i] = rd()].push_back(i);
        int L = n + 1, R = -1;
        for (int i = 1; i <= n; ++i)
        {
            sort(has[i].begin(), has[i].end());
            for (auto x : has[i])
            {
                if (x - L >= i || R - x >= i)
                    End(0);
                L = min(L, x);
                R = max(R, x);
            }
        }
        L = 1, R = n;
        // cout << 1 << '\n';
        for (int i = 1; i <= n; ++i)
        {
            for (auto x : has[i])
            {
                L = max(L, x - i + 1);
                R = min(R, x + i - 1);
            }
        }
        cout << R - L + 1 << '\n';
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
