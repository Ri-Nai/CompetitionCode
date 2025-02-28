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
        int n = rd(), m = rd(), q = rd();
        vector<int> X(m);
        for (int i = 0; i < m; ++i)
            X[i] = rd();
        sort(X.begin(), X.end());
        auto work = [&](int x)
        {
            if (x < X.front())
                return (X.front() - 1);
            if (x > X.back())
                return n - X.back();
            auto it = upper_bound(X.begin(), X.end(), x);
            int r = *it--;
            int l = *it;
            return (r - l) >> 1;
        };
        while (q--)
            cout << work(rd()) << '\n';
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
