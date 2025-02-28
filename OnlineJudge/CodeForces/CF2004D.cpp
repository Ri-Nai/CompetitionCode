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
        int n = rd(), q = rd();
        auto get_id = [&]()
        {
            char c = getchar();
            if (c == 'B')
                return 0;
            if (c == 'G')
                return 1;
            if (c == 'R')
                return 2;
            return 3;
        };
        struct BIT
        {
            vector<int> C;
            int n;
            BIT() : n{}, C{} {}
            BIT(int len) : n(len), C(len + 1) {}
            void Add(int x, int y)
            {
                while (x <= n)
                    C[x] += y, x += x & -x;
            }
            int Sum(int x)
            {
                int res = 0;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
            int query(int l, int r)
            {
                return Sum(r) - Sum(l - 1);
            }
        };
        const int STATUS[] = {1 | 2, 1 | 4, 1 | 8, 2 | 4, 2 | 8, 4 | 8};
        vector<BIT> Tr(16);
        for (auto x : STATUS)
            Tr[x] = BIT(n);
        vector<int> status(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int t1 = get_id(), t2 = get_id();
            status[i] = 1 << t1 | 1 << t2;
            Tr[status[i]].Add(i, 1);
            getchar();
        }
        for (int i = 1; i <= q; ++i)
        {
            int x = rd(), y = rd();
            if (y < x)
                swap(x, y);
            auto get_ans = [&](int x, int y)
            {
                int u = status[x], v = status[y];
                // cout << x << ' ' << y << '\n';
                // cout << u << ' ' << v << '\n';
                if (u & v)
                    return abs(x - y);
                if (Tr[u].query(1, n) + Tr[v].query(1, n) == n)
                    return -1;
                if (Tr[u].query(x, y) + Tr[v].query(x, y) < y - x + 1)
                    return abs(x - y);
                // cout << Tr[u].query(x, y) + Tr[v].query(x, y) << '\n';
                auto check = [&](int l, int r)
                {
                    // cout << l << ' ' << r << ' ' << Tr[u].query(l, r) + Tr[v].query(l, r) << '\n';
                    return r - l + 1 > Tr[u].query(l, r) + Tr[v].query(l, r);
                };
                int l = 1, r = x - 1, res = -1;
                int ans = 1e9;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (check(mid, x - 1))
                        l = mid + 1, res = mid;
                    else r = mid - 1;
                }
                // cout << res << "---\n";
                if (res != -1)
                    ans = min(ans, abs(x - res) + abs(y - res));
                l = y + 1, r = n, res = -1;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (check(y + 1, mid))
                        r = mid - 1, res = mid;
                    else l = mid + 1;
                }
                // cout << res << "---\n";

                if (res != -1)
                    ans = min(ans, abs(x - res) + abs(y - res));
                if (ans == 1e9)
                    return -1;
                return ans;
            };
            cout << get_ans(x, y) << '\n';

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
