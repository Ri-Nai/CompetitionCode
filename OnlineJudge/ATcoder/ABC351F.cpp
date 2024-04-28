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
        vector<int> A, B, C;
        for (int i = 0; i < n; ++i)
            A.push_back(rd());
        C = B = A;
        sort(B.begin(), B.end());
        auto it = unique(B.begin(), B.end());
        B.erase(it, B.end());
        for (int i = 0; i < n; ++i)
            C[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin() + 1;
        struct BIT
        {
            vector<ll> C;
            int n;
            BIT() {}
            BIT(int len) : C(len + 1), n(len) {}
            void Add(int x, int y)
            {
                while (x <= n)
                    C[x] += y, x += x & -x;
            }
            ll Sum(int x)
            {
                ll res = 0;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
        } Sum(n), Cnt(n);
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int cnt = Cnt.Sum(C[i]);
            ll sum = Sum.Sum(C[i]);
            ans += 1ll * cnt * A[i] - sum;
            Sum.Add(C[i], A[i]);
            Cnt.Add(C[i], 1);
        }
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
