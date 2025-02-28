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
        vector<vector<int>> graph(n + 1, vector<int>(m + 1));
        vector<pair<int, int>> pos(n * m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                graph[i][j] = rd();
                pos[graph[i][j]] = {i, j};
            }
        struct Seg
        {
            struct Node
            {
                ll mx, mn;
                Node() : mx{-1}, mn(1e9) {};
                Node operator+(const Node &_) const
                {
                    Node res = *this;
                    if (_.mx > mx)
                        res.mx = _.mx;
                    if (_.mn < mn)
                        res.mn = _.mn;
                    return res;
                }
            };
            vector<Node> Tr;
            int n;
            Seg(int _) : n{_}, Tr(_ + 1 << 2) {}
            Node query(int l, int r, int L, int R, int p)
            {
                if (l == L && R == r)
                    return Tr[p];
                int mid = L + R >> 1;
                if (r <= mid)
                    return query(l, r, L, mid, p << 1);
                else if (l > mid)
                    return query(l, r, mid + 1, R, p << 1 | 1);
                return query(l, mid, L, mid, p << 1) + query(mid + 1, r, mid + 1, R, p << 1 | 1);
            }
            void modify(int x, ll y, int L, int R, int p)
            {
                if (L == R)
                {
                    if (y < Tr[p].mn)
                        Tr[p].mn = y;
                    if (y > Tr[p].mx)
                        Tr[p].mx = y;
                    return;
                }
                int mid = L + R >> 1;
                if (x <= mid)
                    modify(x, y, L, mid, p << 1);
                else
                    modify(x, y, mid + 1, R, p << 1 | 1);
                Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
            }
        } S(n);
        int i;
        for (i = 0; i <= n + m - 2; ++i)
        {
            auto [x, y] = pos[i];
            if (x > 1 && S.query(1, x - 1, 1, n, 1).mx > y)
                break;
            if (x < n && S.query(x + 1, n, 1, n, 1).mn < y)
                break;
            S.modify(x, y, 1, n, 1);
        }
        cout << i << '\n';
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
