#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
    {
        c = getchar();
        c == '-' && (f = -1);
    } while (!isdigit(c));
    while (isdigit(c))
    {
        res = (res << 1) + (res << 3) + (c ^ 48);
        c = getchar();
    }
    return res;
}
int main()
{
    int n = rd();
    vector<vector<int>> E(n + 1);
    int S = 1;
    for (int i = 1; i <= n; ++i)
    {
        int x = rd();
        if (x)
            E[x].push_back(i);
        else
            S = i;
    }
    int flag = 1;
    int ind = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (E[i].size())
            flag &= E[i].size() == E[S].size();
        ind = max(int(E[i].size()), ind);
    }
    printf("%d %s\n", ind, flag ? "yes" : "no");
    vector<int> ans;
    auto dfs = [&](auto self, int u) -> void
    {
        sort(E[u].begin(), E[u].end());
        ans.push_back(u);
        for (int v : E[u])
            self(self, v);
    };
    dfs(dfs, S);
    for (int i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
}
