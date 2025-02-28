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
        vector<int> X(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd();
        struct Seg
        {
            struct Node
            {
                ll mx, mn, sum, lz, inc;
                Node() : mx{}, mn{}, sum{}, lz{}, inc{} {};
                Node(int _) : mx{_}, mn{_}, sum{_}, lz{}, inc{} {};
                Node operator+(const Node &_) const
                {
                    Node res = *this;
                    res.mn = min(res.mn, _.mn);
                    res.mx = max(res.mx, _.mx);
                    res.sum += _.sum;
                    return res;
                }
            };
            vector<Node> Tr;
            int n;
            Seg(int _) : n{_}, Tr(_ + 1 << 2) {}
            void Upd(int p)
            {
                Tr[p].sum = Tr[p].lz + Tr[p]
                Tr[p << 1].lz += Tr[p].lz;
                Tr[p << 1 | 1].lz += Tr[p].lz;
                Tr[p << 1].inc = Tr[p << 1 | 1].inc = Tr[p].inc;
                Tr[p].lz = 0;
                Tr[p].inc = 0;
            }
            void Build(int L, int R, int p, const vector<int> &A)
            {
                if (L == R)
                    Tr[p] = Node(A[L]);
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
            void Update(int l, int r, int x, int pos, int L, int R, int p)
            {
                if (L == l && r == R)
                {
                    Tr[p].lz = x;
                    Tr[p].inc =
                    return;
                }
                int mid = L + R >> 1;
                int mid = L + R >> 1;
                if (r <= mid)
                    return query(l, r, L, mid, p << 1);
                else if (l > mid)
                    return query(l, r, mid + 1, R, p << 1 | 1);
                return query(l, mid, L, mid, p << 1) + query(mid + 1, r, mid + 1, R, p << 1 | 1);
            }
        } T(n);
        int Q = rd();
        for (int i = 1; i <= Q; ++i)
        {
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
