#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    struct Command
    {
        int successVal, successTo;
        int failedVal, failedTo;
        int id;
        Command() {}
        void read(int i)
        {
            id = i;
            string s;
            cin >> s;
            if (s[0] == 'H')
                successTo = successVal = 0;
            else
                cin >> successVal >> s >> successTo >> s;
            cin >> s >> failedVal >> s >> failedTo;
        }
    };
    vector<Command> C(n + 1);
    for (int i = 1; i <= n; ++i)
        C[i].read(i);
    vector<int> inq(n + 1);
    #define STOP() puts("-1"), exit(0)
    const int mod = 998'244'353;
    auto add = [&](int &x, int y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
        return x;
    };
    auto mark = vector(n + 1, vector<pair<int, int>>(1025, {-1, -1}));
    int step = 0;
    auto dfs = [&](auto &&self, int id, int top) -> pair<int, int>
    {
        if (++step > 1114514)
            STOP();
        if (C[id].successVal == top)
            return {1, C[id].successTo};
        if (~mark[id][top].first)
            return mark[id][top];
        if (inq[id])
            STOP();
        inq[id] = 1;
        pair<int, int> &res = mark[id][top];
        pair<int, int> nxt = self(self, C[id].failedTo, C[id].failedVal);
        if (nxt.second == 0)
            res = nxt, add(res.first, 1);
        else
        {
            if (id == nxt.second)
                STOP();
            inq[id] = 0;
            pair<int, int> popnxt = self(self, nxt.second, top);
            res = popnxt;
            add(res.first, nxt.first);
            add(res.first, 1);
        }
        return res;
    };
    auto ans = dfs(dfs, 1, 0);
    cout << ans.first << endl;
}

int main()
{
    solve();
}
