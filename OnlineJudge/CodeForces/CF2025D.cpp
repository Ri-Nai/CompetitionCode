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
        int n = rd(), m = rd();
        struct Seg
        {
            struct Node
            {
                int val, lz;
                Node() : val{}, lz{} {};
                Node operator+(const Node &_) const
                {
                    Node res;
                    res.val = _.val + val;
                    return res;
                }
            };
            vector<Node> Tr;
            int n;
            Seg(int _) : n{_}, Tr(_ + 1 << 2) {}
            void change(int p, int x)
            {
                Tr[p].val += x;
                Tr[p].lz += x;
            }
            void pushDown(int p)
            {
                change(p << 1, Tr[p].lz);
                change(p << 1 | 1, Tr[p].lz);
                Tr[p].lz = 0;
            }

            int query(int l, int r, int L, int R, int p)
            {
                if (l == L && R == r)
                    return Tr[p].val;
                pushDown(p);
                int mid = L + R >> 1;
                if (r <= mid)
                    return query(l, r, L, mid, p << 1);
                else if (l > mid)
                    return query(l, r, mid + 1, R, p << 1 | 1);
                return query(l, mid, L, mid, p << 1) + query(mid + 1, r, mid + 1, R, p << 1 | 1);
            }
            void modify(int x, int y, int L, int R, int p)
            {
                if (L == R)
                {
                    // cout << x << ' ' << y << '\n';
                    if (y > Tr[p].val)
                        Tr[p].val = y;
                    return;
                }
                pushDown(p);
                int mid = L + R >> 1;
                if (x <= mid)
                    modify(x, y, L, mid, p << 1);
                else
                    modify(x, y, mid + 1, R, p << 1 | 1);
                Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
            }
            void update(int l, int r, int x, int L, int R, int p)
            {
                if (l > r)
                    return;
                if (L == l and r == R)
                    return change(p, x);
                pushDown(p);
                int mid = L + R >> 1;
                if (r <= mid)
                    update(l, r, x, L, mid, p << 1);
                else if (l > mid)
                    update(l, r, x, mid + 1, R, p << 1 | 1);
                else
                    update(l, mid, x, L, mid, p << 1), update(mid + 1, r, x, mid + 1, R, p << 1 | 1);
                Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
            }
        } S(m + 3);
        int now = 0;
        for (int i = 1; i <= n; ++i)
        {
            int x = rd();
            if (!x)
            {
                for (int i = now; i >= 0; --i)
                {
                    // cout << i << "  :" << S.query(i, i, 0, m, 1) << '\n';
                    S.modify(i + 1, S.query(i, i, 0, m, 1), 0, m, 1);
                }
                ++now;
            }
            else if (x > 0)
            {
                S.update(x, now, 1, 0, m, 1);
            }
            else if (x < 0)
            {
                x = -x;
                S.update(0, now - x, 1, 0, m, 1);
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; ++i)
            ans = max(ans, S.query(i, i, 0, m, 1));
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
