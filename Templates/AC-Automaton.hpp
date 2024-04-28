#include <bits/stdc++.h>
using namespace std;
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
    vector<int> inq;
    vector<int> cnt;
    void Build()
    {
        queue<int> Q;
        inq.resize(Tr.Nodes.size());
        cnt = inq;
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
            ++cnt[now = Tr.Nodes[now].nxt[c - 'a']];
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
            auto &node = Tr.Nodes[u];
            int v = node.fail;
            for (int id : node.res)
                ans[id] += cnt[u];
            cnt[v] += cnt[u];
            if (!--inq[v])
                Q.push(v);
        }
    }
} AC;
