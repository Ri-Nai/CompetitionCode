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
        int n;
        cin >> n;
        struct person
        {
            int l, r, id;
            bool operator<(const person &_) const
            {
                // return x.first == y.first ? x.second > y.second : x.first < y.first;
                if (l != _.l)
                    return l < _.l;
                return r > _.r;
            }
            bool operator==(const person &_) const
            {
                return l == _.l && r == _.r;
            }
        };
        struct Seg
        {
            struct Node
            {
                ll mx, mn;
                Node() : mx{-1}, mn(1e9) {}
                Node(int x, int y) : mx(x), mn(y) {}
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
            void modify(int x, const pair<int, int> &y, int L, int R, int p)
            {
                if (L == R)
                {
                    Tr[p].mx = y.first;
                    Tr[p].mn = y.second;
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
        // vector<pair<int, int>> seg;
        vector<person> seg;
        vector<pair<int, int>> rs;
        for (int i = 0; i < n; ++i)
        {
            int l, r;
            cin >> l >> r;
            seg.push_back({l, r, i});
            rs.emplace_back(r, i);
        }
        sort(rs.begin(), rs.end());
        sort(seg.begin(), seg.end());
        vector<int> to(n);
        for (int i = 0; i < n; ++i)
            to[rs[i].second] = i + 1;
        vector<int> ans(n);
        set<pair<int, int>> rpos;
        auto Insert = [&](person p)
        {
            auto [l, r, id] = p;
            S.modify(to[id], {l, r}, 1, n, 1);
        };
        auto getAns = [&](person p)
        {
            auto [l, r, id] = p;
            auto it = lower_bound(rs.begin(), rs.end(), make_pair(r, -1));
            auto idx = it - rs.begin() + 1;
            auto res = S.query(idx, n, 1, n, 1);
            if (res.mx == -1)
                ans[id] = 0;
            else
                ans[id] = res.mn - res.mx + 1 - (r - l + 1);
        };
        // for (auto p : seg)
        for (int i = 0; i < n; ++i)
        {
            int j = i + 1;
            for (; j < n && seg[j] == seg[i]; ++j)
                Insert(seg[j]);
            j = i;
            for (; j < n && seg[j] == seg[i]; ++j)
                getAns(seg[j]);
            Insert(seg[i]);
            i = j - 1;
        }
        for (int i = 0; i < n; ++i)
            cout << ans[i] << "\n";
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
