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
    struct SAM
    {
        static constexpr int ALPHABET_SIZE = 26;
        struct Node
        {
            int len;
            int link;
            std::array<int, ALPHABET_SIZE> next;
            Node() : len{}, link{}, next{} {}
        };
        ll ans;
        std::vector<Node> t;
        SAM()
        {
            init();
        }
        SAM(string s)
        {
            init();
            int p = 1;
            ans = 0;
            for (char c : s)
            {
                p = extend(p, c);
                ans += t[p].len - t[t[p].link].len;
            }
        }
        void init()
        {
            t.assign(2, Node());
            t[0].next.fill(1);
            t[0].len = -1;
        }
        int newNode()
        {
            t.emplace_back();
            return t.size() - 1;
        }
        int extend(int p, int c)
        {
            if (t[p].next[c])
            {
                int q = t[p].next[c];
                if (t[q].len == t[p].len + 1)
                {
                    return q;
                }
                int r = newNode();
                t[r].len = t[p].len + 1;
                t[r].link = t[q].link;
                t[r].next = t[q].next;
                t[q].link = r;
                while (t[p].next[c] == q)
                {
                    t[p].next[c] = r;
                    p = t[p].link;
                }
                return r;
            }
            int cur = newNode();
            t[cur].len = t[p].len + 1;
            while (!t[p].next[c])
            {
                t[p].next[c] = cur;
                p = t[p].link;
            }
            t[cur].link = extend(p, c);
            return cur;
        }
        int extend(int p, char c, char offset = 'a')
        {
            return extend(p, c - offset);
        }

        int next(int p, int x)
        {
            return t[p].next[x];
        }

        int next(int p, char c, char offset = 'a')
        {
            return next(p, c - 'a');
        }

        int link(int p)
        {
            return t[p].link;
        }

        int len(int p)
        {
            return t[p].len;
        }

        int size()
        {
            return t.size();
        }
    };
    void solve()
    {
        string s;
        int n;
        cin >> n;
        cin >> s;
        SAM S(s);
        cout << S.ans << '\n';
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

