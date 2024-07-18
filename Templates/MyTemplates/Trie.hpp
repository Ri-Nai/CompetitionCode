#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    struct Node
    {
        vector<int> nxt;
        vector<int> res;
        int fail;
        Node() { nxt.resize(26); }
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
        auto &save = Nodes[now].res;
        if (save.empty() || save.back() != id)
            save.push_back(id);
    }
    void show(string s)
    {
        int now = 0;
        for (auto c : s)
        {
            int nxt = Nodes[now].nxt[c - 'a'];
            if (!nxt)
            {
                cout << '\n';
                return;
            }
            now = nxt;
        }
        for (auto x : Nodes[now].res)
            cout << x << " ";
        cout << '\n';
    }
} Tr;
