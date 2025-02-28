#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 2, -2, 1, -1, 2, -2};
const int dy[] = {2, -2, 1, -1, -2, 2, -1, 1};

int main()
{
    map<pair<int, int>, int> mark;
    vector<int> ans(11);
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    while (!Q.empty())
    {
        auto [x, y, step] = Q.front();
        Q.pop();
        if (step > 10)
            continue;
        if (mark[{x, y}])
            continue;
        // cout << step << ' ' << x << ' ' << y << '\n';
        ++ans[step];
        mark[{x, y}] = 1;
        for (int i = 0; i < 8; ++i)
            Q.push({x + dx[i], y + dy[i], step + 1});
    }
    for (int i = 0; i <= 10; ++i)
    {
        if (i)
            ans[i] += ans[i - 1];
        // cout << ans[i] << ' ';
    }
    // int tot = 0;
    auto solve = [&]() -> unsigned long long
    {
        int n;
        scanf("%d", &n);
        // n = ++tot;
        if (n <= 4)
            return ans[n];
        return ans[4] + 1ull * (120 + 120 + 1ull * (n - 5) * 28) / 2 * (n - 4);

    };
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %llu\n", i, solve());
}
/*
1 8 32 68 96 120 148 176
*/
