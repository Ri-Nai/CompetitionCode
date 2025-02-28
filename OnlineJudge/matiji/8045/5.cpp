#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    auto dp = vector(n, vector<int>(2));
    auto mark = vector(n, vector<int>(2));
    const int inf = 1e9;
    auto dfs = [&](auto &&self, int l, int op) -> int
    {
        if (n - l < k)
            return 0;
        if (mark[l][op])
            return dp[l][op];
        mark[l][op] = 1;
        int &res = dp[l][op];
        priority_queue<int, vector<int>, greater<int>> Q;
        int sum = 0;
        res = op ? inf : -inf;
        for (int i = l; i < l + k; ++i)
            Q.push(a[i]), sum += a[i];
        for (int i = l + k - 1; i < n && i - l + 1 <= k + k; ++i)
        {
            if (i > l + k - 1)
            {
                Q.push(a[i]);
                sum += a[i] - Q.top();
                Q.pop();
            }
            auto nxt = self(self, i + 1, op ^ 1);
            if (op)
                res = min(res, -sum + nxt);
            else 
                res = max(res, sum + nxt);
        }
        return res;
    };
    cout << dfs(dfs, 0, 0) << endl;
}
