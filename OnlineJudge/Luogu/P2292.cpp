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
    struct AC_Automaton
    {
        struct Trie
        {
            struct Node
            {
                vector<int> nxt;
                int fail, mark, len;
                int stat;
                Node(int _ = 0)
                {
                    nxt.resize(26);
                    stat = fail = mark = 0;
                    len = _;
                }
            };
            vector<Node> Nodes;
            Trie() { Nodes.resize(1); }
            int Add_Node(int len)
            {
                int res = Nodes.size();
                Nodes.emplace_back(len + 1);
                return res;
            }
            void Add_String(string s)
            {
                int now = 0;
                for (auto c : s)
                {
                    auto &node = Nodes[now];
                    int &nxt = node.nxt[c - 'a'];
                    if (!nxt)
                        nxt = Add_Node(node.len);
                    now = nxt;
                }
                auto &node = Nodes[now];
                node.mark = 1;
                node.stat = 1 << node.len;
            }
        } Tr;
        vector<int>inq;
        vector<int>cnt;
        void Build()
        {
            queue<int> Q;
            for (int i = 0; i < 26; ++i)
                if (Tr.Nodes[0].nxt[i])
                    Q.push(Tr.Nodes[0].nxt[i]);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                auto &node = Tr.Nodes[u];
                node.stat |= Tr.Nodes[node.fail].stat;
                for (int i = 0; i < 26; ++i)
                {
                    int &p = node.nxt[i];
                    int q = Tr.Nodes[node.fail].nxt[i];
                    if (p)
                    {
                        Tr.Nodes[p].fail = q;
                        Q.push(p);
                    }
                    else
                        p = q;
                }
            }
        }
        auto Query(string s)
        {
            int now = 0;
            vector<int> dp(s.size() + 1);
            dp[0] = 1;
            int ans = 0;
            int last = 1;
            for (int i = 0; i < s.size(); ++i)
            {
                char c = s[i];
                now = Tr.Nodes[now].nxt[c - 'a'];
                int t = Tr.Nodes[now].stat;
                last <<= 1;
                if (last & t)
                    last |= 1, ans = i + 1;
            }
            return ans;
        }
    } AC;
    void solve()
    {
        int n, m;
        cin >> n >> m;
        while (n--)
        {
            string t;
            cin >> t;
            AC.Tr.Add_String(t);
        }
        AC.Build();
        while (m--)
        {
            string s;
            cin >> s;
            cout << AC.Query(s) << '\n';
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    // int t;cin >> t;while(t--)
    T::solve();
}
