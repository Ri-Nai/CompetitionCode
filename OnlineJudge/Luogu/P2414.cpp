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
                vector<int> res;
                int fail, mark, fa;
                Node(int _ = 0)
                {
                    nxt.resize(26);
                    fail = mark = 0;
                    fa = _;
                }
            };
            vector<Node> Nodes;
            Trie() { Nodes.resize(1); }
            int Add_Node(int f)
            {
                int res = Nodes.size();
                Nodes.emplace_back(f);
                return res;
            }
            void Add_nxt(int &now, int c)
            {
                int &nxt = Nodes[now].nxt[c];
                if (!nxt)
                    nxt = Add_Node(now);
                now = nxt;
            }
            void Add_String(string s, int id)
            {
                int now = 0;
                for (auto c : s)
                    Add_nxt(now, c - 'a');
                Nodes[now].res.push_back(id);
            }
        } Tr;
        struct BIT
        {
            vector<int> C;
            int n;
            void init(int len)
            {
                C.resize(len + 1);
                n = len;
            }
            void Add(int x, int y)
            {
                while (x <= n)
                    C[x] += y, x += x & -x;
            }
            int Sum(int x)
            {
                int res = 0;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
        } T;
        int get_size() { return Tr.Nodes.size(); }
        string op;
        vector<vector<int>> E;
        vector<int> L, R;
        vector<int> pos;
        void read()
        {
            cin >> op;
            int now = 0;
            pos.push_back(0);
            for (auto c : op)
            {
                if (islower(c))
                    Tr.Add_nxt(now, c - 'a');
                else if (c == 'B')
                    now = Tr.Nodes[now].fa;
                else if (c == 'P')
                    pos.push_back(now);
            }
        }
        void Build()
        {
            queue<int> Q;
            E.resize(get_size());
            L.resize(get_size());
            R.resize(get_size());
            for (int i = 0; i < 26; ++i)
            {
                int v = Tr.Nodes[0].nxt[i];
                if (!v)
                    continue;
                Q.push(v);
                E[0].push_back(v);
            }
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
                        E[q].push_back(p);
                        Q.push(p);
                    }
                    else
                        p = q;
                }
            }
            int tot = 0;
            auto dfs = [&](auto self, int u) -> void
            {
                L[u] = ++tot;
                for (auto v : E[u])
                    self(self, v);
                R[u] = tot;
            };
            dfs(dfs, 0);
            T.init(tot);
        }
        void Solve(auto quest, auto &ans)
        {
            int now = 0;
            int idx = 0;
            auto query = [&](int x)
            {
                return T.Sum(R[pos[x]]) - T.Sum(L[pos[x]] - 1);
            };
            auto Add = [&](int x, int y)
            {
                T.Add(L[x], y);
            };
            int n = get_size();
            for (auto c : op)
            {
                if (islower(c))
                {
                    Tr.Add_nxt(now, c - 'a');
                    Add(now, 1);
                }
                else if (c == 'B')
                {
                    Add(now, -1);
                    now = Tr.Nodes[now].fa;
                }
                else if (c == 'P')
                {
                    ++idx;
                    for (auto [x, y] : quest[idx])
                    {
                        ans[x] = query(y);
                    }
                }
            }
        }
    } AC;

    void solve()
    {
        AC.read();
        AC.Build();
        int n = AC.pos.size() - 1, m;
        cin >> m;
        vector<vector<pair<int, int>>> quest(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int x = rd(), y = rd();
            quest[y].emplace_back(i, x);
        }
        vector<int> ans(m);
        AC.Solve(quest, ans);
        for (int res : ans)
            printf("%d\n", res);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
