#include <bits/stdc++.h>
#include <ext/pb_ds/hash_policy.hpp>
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
    void solve()
    {
        struct Trie
        {
            struct Node
            {
                array<int, 26> nxt;
                int cnt, ans;
                Node() : nxt{}, cnt{}, ans{} {}
            };
            vector<Node> nodes;
            Trie() : nodes(1) {}
            int newNode()
            {
                nodes.emplace_back();
                return size() - 1;
            }
            int &next(int p, int c)
            {
                return nodes[p].nxt[c];
            }
            int &next(int p, char c)
            {
                return next(p, c - 'a');
            }
            int size()
            {
                return nodes.size();
            }
            void insert(string s)
            {
                int now = 0;
                for (const char &c : s)
                {
                    int nxt = next(now, c);
                    if (!nxt)
                        nxt = next(now, c) = size(), newNode();
                    now = nxt;
                    ++nodes[now].cnt;
                }
                // cout << endl;
                ++nodes[now].ans;
            }
            string getAns(int k)
            {
                string ans;
                int now = 0, cnt = 0;
                while (true)
                {
                    cnt += nodes[now].ans;
                    for (int i = 0; i < 26; ++i)
                        if (nodes[next(now, i)].cnt)
                            ++cnt;
                    if (cnt >= k)
                        return ans;
                    for (int i = 0; i < 26; ++i)
                    {
                        if (!nodes[next(now, i)].cnt)
                            continue;
                        int rest = nodes[next(now, i)].cnt - 1;
                        // cout << cnt << ' ' << rest << ' ' << char(i + 'a') << endl;
                        if (cnt + rest >= k)
                        {
                            --cnt;
                            ans += 'a' + i;
                            now = next(now, i);
                            break;
                        }
                        cnt += rest;
                    }
                }
            }
        } T;
        int n, k;
        cin >> n >> k;
        while (n--)
        {
            string s;
            cin >> s;
            // cout << s << endl;
            T.insert(s);
        }
        string ans = T.getAns(k);
        if (ans.empty())
            ans = "EMPTY";
        cout << ans << endl;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
