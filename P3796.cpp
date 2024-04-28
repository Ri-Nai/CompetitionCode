#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
namespace T
{
    bool solve()
    {
        struct AC_Automaton
        {
            struct Trie
            {
                struct Node
                {
                    vector<int> nxt;
                    vector<int> res;
                    int fail, mark;
                    Node()
                    {
                        nxt.resize(26);
                        fail = mark = 0;
                    }
                };
                vector<Node> Nodes;
                Trie() { Nodes.resize(1); }
                int Add_Node()
                {
                    int res = Nodes.size();
                    Nodes.emplace_back();
                    return res;
                }
                void Add_String(string s, int id)
                {
                    int now = 0;
                    for (auto c : s)
                    {
                        int &nxt = Nodes[now].nxt[c - 'a'];
                        if (!nxt)
                            nxt = Add_Node();
                        now = nxt;
                    }
                    Nodes[now].res.push_back(id);
                }
            } Tr;
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
            auto Query(string s, vector<int> &ans)
            {
                int now = 0;
                for (auto c : s)
                {
                    now = Tr.Nodes[now].nxt[c - 'a'];
                    int nxt = now;
                    while (nxt)
                    {
                        auto &node = Tr.Nodes[nxt];
                        for (int id : node.res)
                            ++ans[id];
                        nxt = node.fail;
                    }
                }
            }
        } AC;
        int n;
        cin >> n;
        if (!n) return 0;
        vector<string> S(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> S[i];
            AC.Tr.Add_String(S[i], i);
        }
        AC.Build();
        string s;
        cin >> s;
        vector<int>res(n+1);
        AC.Query(s, res);
        int mx = 0;
        for (int i = 1; i <= n; ++i)
            if (mx < res[i])
                mx = res[i];
        cout << mx << '\n';
        for (int i = 1; i <= n; ++i)
            if (mx == res[i])
                cout << S[i] << '\n';
        return 1;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    while (T::solve());

}
