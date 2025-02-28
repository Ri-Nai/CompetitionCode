#include <bits/stdc++.h>
using namespace std;
int get_ans(string s)
{
    int ans = 0;
    const string t = "soyo";
    for (int i = 0; i < s.size(); ++i)
    {
        bool flag = 1;
        for (int j = 0; j < 4; ++j)
        {
            if (i + j >= s.size())
                flag = 0;
            else if (s[i + j] != t[j])
                flag = 0;
        }
        ans += flag;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    typedef long long ll;
    const int mod = 998244353;
    vector<int> in(n + 1);
    vector<ll> ans(n + 1, -1);
    vector<string> s(n + 1);
    vector<vector<int>> E(n + 1), fa(n + 1);
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
    {
        int op;
        cin >> op;
        string now;
        if (op == 1)
            cin >> s[i], Q.push(i);
        else
        {
            int k;
            cin >> k;
            in[i] = k;
            while (k--)
            {
                int v;
                cin >> v;
                fa[i].push_back(v);
                E[v].push_back(i);
            }
        }
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int f : fa[u])
            s[u] += s[f];
        ans[u] = get_ans(s[u]);
        for (int v : E[u])
            if (!--in[v])
                Q.push(v);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';

}
