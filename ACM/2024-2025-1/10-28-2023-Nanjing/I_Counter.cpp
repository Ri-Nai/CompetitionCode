#include <bits/stdc++.h>
using namespace std;

string solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> op;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        op.emplace_back(x, y);
    }
    sort(op.begin(), op.end());
    int last = 0, val = 0;
    for (int i = 0; i < m; ++i)
    {
        auto [now, nowval] = op[i];
        int diff = now - last;
        if (val + diff != nowval && diff < nowval + 1)
            return "No";
        last = now;
        val = nowval;
    }
    return "Yes";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        cout << solve() << '\n';
}
