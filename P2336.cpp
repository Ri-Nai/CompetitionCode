#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
typedef vector<int> STR;

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
                map<int, int> nxt;
                vector<int> res;
                int fail, mark;
                Node()
                {
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
            void Add_String(STR s, int id)
            {
                int now = 0;
                for (auto c : s)
                {
                    int &nxt = Nodes[now].nxt[c];
                    if (!nxt)
                        nxt = Add_Node();
                    now = nxt;
                }
                Nodes[now].res.push_back(id);
            }
        } Tr;
        vector<int> inq;
        vector<int> cnt;
        void Build()
        {
            queue<int> Q;
            inq.resize(Tr.Nodes.size());
            cnt = inq;
            for (auto [x, y] : Tr.Nodes[0].nxt)
                Q.push(y);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                auto &node = Tr.Nodes[u];
                for (auto [c, v] : node.nxt)
                {
                    auto get_fail=[&](int u, int c)
                    {
                        while (u && !Tr.Nodes[u].nxt[c])
                            u = Tr.Nodes[u].fail;
                        return Tr.Nodes[u].nxt[c];
                    };
                    Tr.Nodes[v].fail = get_fail(node.fail, c);
                    Q.push(v); ++inq[v];
                }
            }
        }
        void Query(string s, vector<int> &ans)
        {
            int now = 0;
            for (auto c : s)
                cnt[now = Tr.Nodes[now].nxt[c - 'a']] |= 1;
        }
        auto Topo(vector<int> &ans)
        {
            queue<int> Q;
            int res = 0;
            for (int i = 1; i < inq.size(); ++i)
                if (!inq[i])
                    Q.push(i);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                auto &node = Tr.Nodes[u];
                int v = node.fail;
                for (int id : node.res)
                    ans[id] += cnt[u];
                cnt[v] |= cnt[u];
                cnt[u] = 0;
                if (!--inq[v])
                    Q.push(v);
            }
        }
    } AC;
    void solve()
    {
        int n = rd(), m = rd();
        vector<STR> A(n + 1), B(m + 1);
        auto read_string = [&]()
        {
            int n = rd();
            STR ans;
            while (n--)
                ans.push_back(rd());
            return ans;
        };
        for (int i = 1; i <= n; ++i)
        {
            auto x = read_string();
            auto y = read_string();
            for (auto a : x)
                A[i].push_back(a);
            A[i].push_back(-1);
            for (auto b : y)
                A[i].push_back(b);
        }
        for (int i = 1; i <= m; ++i)
            B[i] = read_string(),
            AC.Tr.Add_String(B[i], i);
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
