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
        int n = rd(), x = rd(), k = rd();
        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            A[i] = rd();
        }
        int l = k, r = n, res = 0;
        auto check = [&](int t)
        {
            priority_queue<int> Q;
            for (int i = 1; i <= t; ++i)
                Q.push(A[i]);
            for (int i = 1; i <= k && !Q.empty(); ++i)
                Q.pop();
            int p = x;
            while (!Q.empty())
            {
                p -= Q.top();
                Q.pop();
                if (p <= 0)
                    return false;
            }
            return true;
        };
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                l = mid + 1, res = mid;
            else r = mid - 1;
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
