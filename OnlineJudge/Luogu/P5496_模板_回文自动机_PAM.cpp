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
    struct PAM
    {
        static constexpr int ALPHABET_SIZE = 28;
        struct Node
        {
            int len;
            int link;
            int cnt;
            std::array<int, ALPHABET_SIZE> next;
            Node() : len{}, link{}, cnt{}, next{} {}
        };
        std::vector<Node> t;
        int suff;
        std::string s;

        PAM() { init(); }

        void init()
        {
            t.assign(2, Node());
            t[0].len = -1;
            suff = 1;
            s.clear();
        }

        int newNode()
        {
            t.emplace_back();
            return t.size() - 1;
        }

        Node last()
        {
            return t[suff];
        }

        int findFail(int cur, int pos)
        {
            while (pos - 1 - t[cur].len < 0 || s[pos - 1 - t[cur].len] != s[pos])
                cur = t[cur].link;
            return cur;
        }

        bool add(char c, char offset = 'a')
        {
            int pos = s.size();
            s += c;
            int let = c - offset;
            int cur = suff, curlen = 0;

            cur = findFail(cur, pos);
            if (t[cur].next[let])
            {
                suff = t[cur].next[let];
                return false;
            }

            int num = newNode();
            suff = num;
            t[num].len = t[cur].len + 2;
            t[cur].next[let] = num;

            if (t[num].len == 1)
            {
                t[num].link = 1;
                t[num].cnt = 1;
                return true;
            }

            cur = findFail(t[cur].link, pos);
            t[num].link = t[cur].next[let];
            t[num].cnt = 1 + t[t[num].link].cnt;

            return true;
        }
    };
    void solve()
    {
        string s;
        cin >> s;
        int ans = 0;
        PAM pam;
        for (auto &c : s)
        {
            c = (c - 97 + ans) % 26 + 97;
            pam.add(c);
            ans = pam.last().cnt;
            cout << ans << " ";
        }
        cout << '\n';
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
