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
    void solve()
    {
        int n;
        cin >> n;
        // cout<<n<<'\n';
        for (int i = 1; i <= n; ++i)
        {
            int m;
            cin >> m;
            while (m--)
            {
                string s;
                cin >> s;
                Tr.Add_String(s, i);
            }
        }
        cin >> n;
        while (n--)
        {
            string s;
            cin >> s;
            Tr.show(s);
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    // int t;cin > >t;while(t--)
    T::solve();
}
