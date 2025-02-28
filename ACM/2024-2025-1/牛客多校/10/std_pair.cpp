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
    struct Tree
    {
        struct Node
        {
            int type, fa, l, r;
            Node() : type{}, fa{}, l{}, r{} {}
        };
        vector<Node> Tr;
        Tree() : Tr(1) {}
        int Newnode()
        {
            Tr.emplace_back();
            return Tr.size() - 1;
        };
        void insert(string s)
        {
            int p = Newnode();
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == 'p')
                {
                    int q = Newnode();
                    Tr[p].type = 0;
                    Tr[p].l = q;
                    Tr[q].fa = p;
                    p = q;
                    i += 4;
                }
                else if (s[i] == '>')
                {
                    p = Tr[p].fa;
                }
                else if (s[i] == ',')
                {
                    p = Tr[p].fa;
                    int q = Newnode();
                    Tr[p].r = q;
                    Tr[q].fa = p;
                    p = q;
                }
                else if (s[i] == 'd')
                {
                    Tr[p].type = 2;
                    i += 5;
                }
                else if (s[i] == 'i')
                {
                    Tr[p].type = 1;
                    i += 2;
                }
            }
        }
        string show(int p)
        {
            if (Tr[p].type == 0)
                return "pair<" + show(Tr[p].l) + "," + show(Tr[p].r) + ">";
            if (Tr[p].type == 1)
                return "int";
            return "double";
        }
        void Query(string s)
        {
            int p = 1;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == 'f')
                {
                    p = Tr[p].l;
                    i += 5;
                }
                else
                {
                    p = Tr[p].r;
                    i += 6;
                }
            }
            cout << show(p) << '\n';
        }
    };
    void solve()
    {
        int n, q;
        cin >> n >> q;
        map<string, int> id;
        vector<Tree> has(n);
        for (int i = 0; i < n; ++i)
        {
            string type, name;
            cin >> type >> name;
            name.pop_back();
            id[name] = i;
            has[i].insert(type);
            has[i].show(1);
        }
        while (q--)
        {
            string query;
            cin >> query;
            int pos = query.find_first_of('.');
            if (pos == -1)
                pos = query.size();
            string name = query.substr(0, pos);
            int now = id[name];
            string t;
            if (pos != query.size())
                t = query.substr(pos + 1);
            has[now].Query(t);
        }
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
