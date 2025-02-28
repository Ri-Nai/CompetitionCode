#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, lim = 16;
long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}
int n, q, m;
long long a[N], b[N];
struct Seg
{
    long long Max1, Max2;
} tr[N << 2];
Seg merge(Seg l, Seg r)
{
    static Seg ret;
    ret.Max1 = max(l.Max1, r.Max1);
    ret.Max2 = 0;
    if (l.Max1 != ret.Max1)
        ret.Max2 = max(ret.Max2, l.Max1);
    if (l.Max2 != ret.Max1)
        ret.Max2 = max(ret.Max2, l.Max2);
    if (r.Max1 != ret.Max1)
        ret.Max2 = max(ret.Max2, r.Max1);
    if (r.Max2 != ret.Max1)
        ret.Max2 = max(ret.Max2, r.Max2);
    return ret;
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        tr[p].Max1 = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tr[p] = merge(tr[p << 1], tr[p << 1 | 1]);
}
Seg query(int p, int l, int r, int nl, int nr)
{
    if (l == nl && r == nr)
        return tr[p];
    int mid = l + r >> 1;
    if (nr <= mid)
        return query(p << 1, l, mid, nl, nr);
    else if (nl > mid)
        return query(p << 1 | 1, mid + 1, r, nl, nr);
    else
        return merge(query(p << 1, l, mid, nl, mid), query(p << 1 | 1, mid + 1, r, mid + 1, nr));
}
vector<int> pos[N];
struct Node
{
    vector<long long> a[17];
} pt[N];
long long st[N][17];
int glen[N];
long long Gcd(int l, int r)
{
    if (r < l)
        return 0;
    int len = r - l + 1, tlen = glen[len];
    len = (1 << tlen);
    return gcd(st[l][tlen], st[r - len + 1][tlen]);
}
long long ggcd(int type, int l, int r)
{
    if (r < l)
        return 0;
    int len = r - l + 1, tlen = glen[len];
    len = (1 << tlen);
    return gcd(pt[type].a[tlen][l], pt[type].a[tlen][r - len + 1]);
}
long long check(long long val, int l, int r)
{
    int tval = lower_bound(b + 1, b + 1 + m, val) - b;
    int tl = lower_bound(pos[tval].begin(), pos[tval].end(), l) - pos[tval].begin();
    int tr = upper_bound(pos[tval].begin(), pos[tval].end(), r) - pos[tval].begin() - 1;
    long long tgcd = ggcd(tval, tl, tr - 1);
    tgcd = gcd(tgcd, Gcd(l, pos[tval][tl] - 1));
    tgcd = gcd(tgcd, Gcd(pos[tval][tr] + 1, r));
    return val + tgcd;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], b[i] = a[i];
    build(1, 1, n);
    sort(b + 1, b + 1 + n);
    m = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; ++i)
        pos[lower_bound(b + 1, b + 1 + m, a[i]) - b].push_back(i);
    for (int i = 1; i <= n; ++i)
        st[i][0] = a[i];
    for (int j = 1; j <= lim; ++j)
        for (int i = 1; i <= n - (1 << j) + 1; ++i)
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    glen[1] = 0;
    for (int i = 2; i <= n; ++i)
        glen[i] = glen[i >> 1] + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (pos[i].size())
        {
            for (int j = 0; j <= lim; ++j)
                pt[i].a[j].resize(pos[i].size());
            pos[i].push_back(n + 1);
        }
        for (int j = 0; j < (int)pos[i].size() - 1; ++j)
            pt[i].a[0][j] = Gcd(pos[i][j] + 1, pos[i][j + 1] - 1);
        for (int k = 1; k <= lim; ++k)
            for (int j = 0; j <= (int)pos[i].size() - 1 - (1 << k); ++j)
                pt[i].a[k][j] = gcd(pt[i].a[k - 1][j], pt[i].a[k - 1][j + (1 << k - 1)]);
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        Seg tmp = query(1, 1, n, l, r);
        if (tmp.Max2 == 0)
        {
            cout << tmp.Max1 * 2 << endl;
            continue;
        }
        long long ans = check(tmp.Max1, l, r);
        ans = max(ans, check(tmp.Max2, l, r));
        cout << ans << endl;
    }
    return 0;
}
/*


6
3 6 2 5 4 4
3
1 3
4 6
1 6


*/
