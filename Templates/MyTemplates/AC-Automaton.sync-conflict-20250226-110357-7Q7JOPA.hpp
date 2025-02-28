#include <bits/stdc++.h>
using namespace std;
struct AC_Automaton
{
    struct Trie
    {
        static constexpr int ALPHABET_SIZE = 26;
        struct Node
        {
            vector<int> res;
            array<int, ALPHABET_SIZE> nxt;
            int fail, mark;
            Node() : nxt{}, fail{}, mark{} {}
        };
        vector<Node> nodes;
        Trie() { nodes.resize(1); }
        int& next(int p, int x)
        {
            return nodes[p].nxt[x];
        }

        int& next(int p, char c, char offset = 'a')
        {
            return next(p, c - 'a');
        }
        int& fail(int p)
        {
            return nodes[p].fail;
        }
        int Add_Node()
        {
            int res = nodes.size();
            nodes.emplace_back();
            return res;
        }
        void Add_String(string s, int id)
        {
            int now = 0;
            for (auto c : s)
            {
                int &nxt = next(now, c);
                if (!nxt)
                    nxt = Add_Node();
                now = nxt;
            }
            nodes[now].res.push_back(id);
        }
    } Tr;
    vector<int> inq;
    vector<int> cnt;
    int& next(int p, int x)
    {
        return Tr.next(p, x);
    }
    int& next(int p, char c, char offset = 'a')
    {
        return Tr.next(p, c, offset);
    }
    int& fail(int p)
    {
        return Tr.fail(p);
    }
    void Build()
    {
        queue<int> Q;
        inq.resize(Tr.nodes.size());
        cnt = inq;
        for (int i = 0; i < 26; ++i)
            if (next(0, i))
                Q.push(next(0, i));
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (int i = 0; i < 26; ++i)
            {
                int &p = next(u, i);
                int q = Tr.nodes[fail(u)].nxt[i];
                if (p)
                {
                    fail(p) = q;
                    ++inq[q];
                    Q.push(p);
                }
                else
                    p = q;
            }
        }
    }
    void Query(string s, vector<int> &ans)
    {
        int now = 0;
        for (auto c : s)
            ++cnt[now = next(now, c)];
    }
    void Topo(vector<int> &ans)
    {
        queue<int> Q;
        for (int i = 1; i < inq.size(); ++i)
            if (!inq[i])
                Q.push(i);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            auto &node = Tr.nodes[u];
            int v = node.fail;
            for (int id : node.res)
                ans[id] += cnt[u];
            cnt[v] += cnt[u];
            if (!--inq[v])
                Q.push(v);
        }
    }
} AC;
