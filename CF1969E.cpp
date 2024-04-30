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
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    const int maxn = 3e5 + 5;
    struct Seg
    {
        int l, r, mx;
    } tree[maxn << 2];
    void build(int l, int r, int p)
    {
        tree[p].l = l;
        tree[p].r = r;
        if (l == r)
            return tree[p].mx = 0, void();
        int mid = l + r >> 1;
        tree[p].mx = 0;
        build(l, mid, ls);
        build(mid + 1, r, rs);
    }
    int query(int l, int r, int p)
    {
        if (r < l)return -1;
        if (tree[p].l == l && tree[p].r == r)
            return tree[p].mx;
        int mid = tree[p].l + tree[p].r >> 1;
        if (r <= mid)
            return query(l, r, ls);
        else if (l > mid)
            return query(l, r, rs);
        else
            return std::max(query(l, mid, ls), query(mid + 1, r, rs));
    }
    void update(int x, int a, int p)
    {
        if (tree[p].l == tree[p].r)
            return tree[p].mx = a, void();
        int mid = tree[p].l + tree[p].r >> 1;
        if (x <= mid)
            update(x, a, ls);
        else
            update(x, a, rs);
        tree[p].mx = std::max(tree[ls].mx, tree[rs].mx);
    }
    void solve()
    {
        int n = rd();
        vector<int> A(n + 1), nxt(n + 1, n + 1), pre(n + 1, 0), preval(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            A[i] = rd();
            pre[i] = preval[A[i]];
            nxt[pre[i]] = i;
            preval[A[i]] = i;
        }
        build(1, n, 1);
        for (int i = 1; i <= n; ++i)
            update(i, nxt[i], 1);
        int end_pos = n + 1;
        set<int> S;
        int ans = 0, mx = 0;
        for (int i = n; i >= 1; --i)
        {
            if (S.count(A[i]))
            {
                if (nxt[i] < end_pos)
                {
                    S.erase(A[i]);
                    if (S.empty() || query(i + 1, nxt[i] - 1, 1) < nxt[i])
                    {
                        end_pos = i, ++ans;
                        S.clear();
                        continue;
                        // cout << i << ' ';
                    }
                    S.insert(A[i]);
                }
            }
            else
            {
                S.insert(A[i]);
            }
        }
        cout << ans << '\n';
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
