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
    const int mod = 998244353;
    typedef long long ll;
    struct Str
    {
        int ans;
        string pre, suf;
        Str(){ans = 0, pre = suf = "";}
        Str(string s)
        {
            if (s.size() < 3)
                pre = suf = s;
            else pre = s.substr(0, 3), suf = s.substr(s.size() - 3, 3);
            ans = get_ans(s);
        }
        Str(int ans_, string pre_, string suf_) : ans(ans_), pre(pre_), suf(suf_) {}
        Str operator + (const Str &_) const
        {
            string middle = suf + _.pre;
            int res = (ans + _.ans + get_ans(middle)) % mod;
            string pre_(pre), suf_(_.suf);
            if (pre_.size() < 3)
                pre_ = pre + _.pre;
            if (suf_.size() < 3)
                suf_ = suf + _.suf;
            if (pre_.size() > 3)
                pre_ = pre_.substr(0, 3);
            if (suf_.size() > 3)
                suf_ = suf_.substr(suf_.size() - 3, 3);
            assert(pre_.size() <= 3);
            assert(suf_.size() <= 3);
            return Str(res, pre_, suf_);
        }
    };
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> in(n + 1);
    vector<ll> ans(n + 1, -1);
    vector<Str> S(n + 1);
    vector<vector<int>> E(n + 1), fa(n + 1);
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
    {
        int op;
        cin >> op;
        string now;
        if (op == 1)
        {
            cin >> now;
            S[i] = Str(now);
            Q.push(i);
        }
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
            S[u] = S[u] + S[f];
        for (int v : E[u])
            if (!--in[v])
                Q.push(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            cout << S[i].ans << endl;
        else cout << -1 << endl;
}
