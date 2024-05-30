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
        vector<int> A;
        for (int i = 0; i < n; ++i)
            A.push_back(rd());
        map<pair<int, int>, int> pre, mid, suf;
        map<tuple<int, int, int>, int> tot;
        long long ans = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            int &p = pre[{A[i + 1], A[i + 2]}];
            int &m = mid[{A[i], A[i + 2]}];
            int &s = suf[{A[i], A[i + 1]}];
            int &t = tot[{A[i], A[i + 1], A[i + 2]}];
            ans += p + m + s - 3 * t;
            ++p, ++m, ++s, ++t;
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
