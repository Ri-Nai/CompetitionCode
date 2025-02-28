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
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);

        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = n; i >= 1; --i)
            a[i] = abs(a[i] - a[i - 1]);
        struct ST_Table
        {
            function<int(int, int)> get;
            vector<vector<int>> ST;
            vector<int> lg;
            int n;
            ST_Table() {}
            ST_Table(int _n, const vector<int> &arr, function<int(int, int)> _get)
            {
                n = _n;
                get = _get;
                lg.resize(n + 1);
                for (int i = 2; i <= n; ++i)
                    lg[i] = lg[i >> 1] + 1;
                ST.assign(n + 1, vector<int>(lg[n] + 1));
                for (int i = 1; i <= n; ++i)
                    ST[i][0] = arr[i];
                for (int j = 1; j <= lg[n]; ++j)
                    for (int i = 1; i <= n - (1 << j) + 1; ++i)
                        ST[i][j] = get(ST[i][j - 1], ST[i + (1 << j - 1)][j - 1]);
            }
            int query(int l, int r)
            {
                if (r < l)
                    return get(query(1, r), query(l, n));
                int p = lg[r - l + 1];
                return get(ST[l][p], ST[r - (1 << p) + 1][p]);
            }
        } G(n, a, [&](int x, int y)
            { return gcd(x, y);});
        auto query = [&](int l, int r)
        {
            if (l == r)
                return 0;
            return G.query(l + 1, r);
        };
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << " ";
        }
        cout << endl;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
