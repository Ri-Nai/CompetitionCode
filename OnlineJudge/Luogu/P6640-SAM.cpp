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
        static constexpr int ALPHABET_SIZE = 2;
        struct Node
        {
            int len;
            int link;
            std::array<int, ALPHABET_SIZE> next;
            Node() : len{}, link{}, next{} {}
        };
        std::vector<Node> t;
        SAM()
        {
            init();
        }
        SAM(string s)
        {
            init();
            int p = 1;
            for (char c : s)
                p = extend(p, c);
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
        auto get_lcs(string s)
        {
            vector<int> res(s.size());
            int p = 1, l = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                char c = s[i];
                while (!next(p, c))
                    p = link(p), l = len(p);
                res[i] = ++l;
                p = next(p, c);
            }
            return res;
        }
    };

    void solve()
    {
        string s, t;
        cin >> s >> t;
        SAM S(t);
        auto ans = S.get_lcs(s);
        int n = s.size();
        vector<int> lg2(n + 1);
        for (int i = 2; i <= n; ++i)
            lg2[i] = lg2[i >> 1] + 1;
        vector<vector<int>> ST(n, vector<int>(lg2[n] + 1));
        for (int i = 0; i < n; ++i)
            ST[i][0] = ans[i];
        for (int i = 1; i <= lg2[n]; ++i)
        {
            int l = 1 << i;
            for (int j = 0; j <= n - l; ++j)
                ST[j][i] = max(ST[j + (l >> 1)][i - 1], ST[j][i - 1]);
        }
        auto query = [&](int l, int r)
        {
            auto query_ST = [&](int l, int r)
            {
                int p = lg2[r - l + 1];
                if (r < l)
                    return 0;
                return max(ST[l][p], ST[r - (1 << p) + 1][p]);
            };
            auto find_pos = [&](int l, int r)
            {
                int L = l, R = r, res = r + 1;
                while (L <= R)
                {
                    int mid = L + R >> 1;
                    if (ans[mid] <= mid - l + 1)
                        res = mid, R = mid - 1;
                    else
                        L = mid + 1;
                }
                return res;
            };
            int pos = find_pos(l, r);
            query_ST(pos, r);
            return max(pos - l, query_ST(pos, r));
        };
        for (int q = rd(); q--;)
        {
            int l = rd() - 1, r = rd() - 1;
            cout << query(l, r) << '\n';
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
