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
        vector<int> A(n + 1), B(m + 1), pos(n + 1), mark(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd(), pos[A[i]] = i;
        vector<set<int>> has(n + 1);

        struct Seg
        {
            struct Node
            {
                int mx, mn, xp, np;
                Node() : mx{}, mn{}, xp{-1}, np{-1} {};
                Node(int _, int p) : mx{_}, mn{_}, xp{p}, np{p} {};
                Node operator+(const Node &_) const
                {
                    Node res = *this;
                    if (_.mx > mx)
                        res.xp = _.xp, res.mx = _.mx;
                    if (_.mn < mn)
                        res.np = _.np, res.mn = _.mn;
                    return res;
                }
            };
            vector<Node> Tr;
            int n;
            Seg(int _) : n{_}, Tr(_ + 1 << 2) {}
            void Build(int L, int R, int p, const vector<int> &A)
            {
                if (L == R)
                    Tr[p] = Node(A[L], L);
                else
                {
                    int mid = L + R >> 1;
                    Build(L, mid, p << 1, A);
                    Build(mid + 1, R, p << 1 | 1, A);
                    Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
                }
            }
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
            void Modify(int x, int y, int L, int R, int p)
            {
                if (x > n)
                    return;
                if (L == R)
                {
                    Tr[p] = Node(y, x);
                    return;
                }
                int mid = L + R >> 1;
                if (x <= mid)
                    Modify(x, y, L, mid, p << 1);
                else
                    Modify(x, y, mid + 1, R, p << 1 | 1);
                Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
            }
        } S(n);


        for (int i = 1; i <= m; ++i)
        {
            B[i] = pos[rd()];
            has[B[i]].insert(i);
        }
        auto get_val = [&](int id) -> int
        {
            if (id == 0)
                return -1;
            if (has[id].empty())
                return 1e9 + id;
            return *has[id].begin();
        };
        auto get_diff = [&](int id) -> int
        {
            if (id > n)
                return -1;
            return get_val(id) - get_val(id - 1);
        };
        for (int i = 1; i <= n; ++i)
            S.Modify(i, get_diff(i), 1, n, 1);
        auto work = [&]()
        {
            if (S.query(1, n, 1, n, 1).mn > 0)
                End("YA");
            End("TIDAK");
        };
        work();
        while (q--)
        {
            int x = rd(), y = rd();
            has[B[x]].erase(x);
            S.Modify(B[x], get_diff(B[x]), 1, n, 1);
            S.Modify(B[x] + 1, get_diff(B[x] + 1), 1, n, 1);
            B[x] = pos[y];
            // for (int i = 1; i <= m; ++i)
            //     cout << B[i] << " \n"[i == n];
            has[B[x]].insert(x);
            S.Modify(B[x], get_diff(B[x]), 1, n, 1);
            S.Modify(B[x] + 1, get_diff(B[x] + 1), 1, n, 1);
            work();
        }
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
