#include <bits/stdc++.h>
using namespace std;
struct ST_TABLE
{
    int n;
    vector<int> lg;
    vector<vector<int>> res;
    function<int(int, int)> operate;
    ST_TABLE() {}
    ST_TABLE(int _, const vector<int> &A, auto func)
    {
        operate = func;
        n = _;
        lg.resize(n + 1);
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i >> 1] + 1;
        res.assign(n + 1, vector<int>(lg[n] + 1));
        for (int i = 1; i <= n; ++i)
            res[i][0] = A[i];
        for (int j = 1; j <= lg[n]; ++j)
            for (int i = 1; i <= n; ++i)
            {
                if (i + (1 << j) - 1 > n)
                    continue;
                res[i][j] = operate(res[i][j - 1], res[i + (1 << j - 1)][j - 1]);
            }
    }
    int query(int l, int r, int p)
    {
        if (r < l)
            return -1;
        int t = lg[r - l + 1];
        return operate(res[l][t], res[r - (1 << t) + 1][t]);
    }
};
