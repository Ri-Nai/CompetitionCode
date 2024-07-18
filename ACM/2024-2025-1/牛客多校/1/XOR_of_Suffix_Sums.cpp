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
        int m = rd();
        struct BIT
        {
            vector<int> C;
            int n;
            BIT(int len) : n(len), C(len + 1) {}
            void Add(int x, int y)
            {
                x %= n;
                ++x;
                while (x <= n)
                    C[x] += y, x += x & -x;
            }
            int Sum(int x)
            {
                ++x;
                int res = 0;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
            int Query(int l, int r)
            {
                if (r >= n)
                    return Sum(n - 1) - Sum(l - 1) + Sum(r - n);
                if (l < 0)
                    return Sum(n - 1) - Sum(l + n - 1) + Sum(r);
                return Sum(r) - Sum(l - 1);
            }
            int check(int x)
            {
                x %= n;
                int m = n >> 1;
                int res = Query(m - x, n - x - 1);
                return Query(m - x, n - x - 1) & 1;
            }
        };
        const int P = 1 << 21;
        vector<BIT>cnt;
        vector<int>S;
        for (int i = 0; i <= 20; ++i)
            cnt.emplace_back(1 << i + 1);
        auto Insert = [&](int x, int y)
        {
            x = x % P;
            for (int i = 0; i <= 20; ++i)
                cnt[i].Add(P - x, y);
            if (y == 1)
                S.push_back(x);
            else S.pop_back();
        };
        Insert(0, 1);
        while (m--)
        {
            int x = rd(), y = rd();
            while (x--)
                Insert(S.back(), -1);
            Insert(S.back() + y, 1);
            int ans = 0;
            for (int i = 0; i <= 20; ++i)
                ans |= cnt[i].check(S.back()) << i;
            cout << ans << '\n';
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
