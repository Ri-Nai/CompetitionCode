#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<int> X(n + 1), Y(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &X[i], &Y[i]);
    if (n == 3)
    {
        puts("Yes");
        return 0;
    }
    auto sign = [&](auto x)
    {
        if (x > 0)
            return 1;
        if (x < 0)
            return -1;
        return 0;
    };
    auto get_cross = [&](int x1, int y1, int x2, int y2)
    {
        return 1ll * x1 * y2 - 1ll * x2 * y1;
    };
    auto get_cross_id = [&](int a, int b, int c)
    {
        return sign(get_cross(X[b] - X[a], Y[b] - Y[a], X[c] - X[b], Y[c] - Y[b]));
    };
    auto nxt = [&](int x)
    { return x % n + 1; };
    auto pre = [&](int x)
    { return (x + n - 2) % n + 1; };
    vector<int> cross(n + 1);
    vector<vector<int>> has(3);
    for (int i = 1; i <= n; ++i)
        cross[i] = get_cross_id((i + n - 2) % n + 1, i, i % n + 1);
    vector<int> lg(n + 1);
    auto valid = [&](int x)
    {
        return cross[pre(x)] * cross[nxt(x)] < 0;
    };
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    struct ST_Table
    {
        function<int(int, int)> get;
        vector<vector<int>> ST;
        vector<int> lg;
        int n;
        ST_Table() {}
        ST_Table(int _n, vector<int> cross, function<int(int, int)> _get)
        {
            n = _n;
            get = _get;
            lg.resize(n + 1);
            for (int i = 2; i <= n; ++i)
                lg[i] = lg[i >> 1] + 1;
            ST.assign(n + 1, vector<int>(lg[n] + 1));
            for (int i = 1; i <= n; ++i)
                ST[i][0] = cross[i];
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
    } MX(n, cross, [&](int x, int y)
         { return max(x, y); }),
        MN(n, cross, [&](int x, int y)
           { return min(x, y); });
    auto check = [&](int l, int r)
    {
        return MN.query(l, r) * MX.query(l, r) > 0;
    };
    int flag = 0;
    for (int i = 1; !flag && i <= n; ++i)
    {
        if (!valid(i))
            continue;
        for (int j = i + 2; !flag && j <= n; ++j)
        {
            if (n - (j - i) < 2)
                continue;
            if (!valid(j))
                continue;
            if (check(nxt(i), pre(j)) && check(nxt(j), pre(i)))
                flag = 1;
        }
    }
    if (flag)
        puts("Yes");
    else
        puts("No");
}
/*
6
0 1
-1 2
-1 -2
0 -1
1 -2
1 2


8
-1 0
-1 1
-2 1
-2 -1
2 -1
2 1
1 1
1 0
*/
