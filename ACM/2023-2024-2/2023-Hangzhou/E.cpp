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
    void solve()
    {
        int n = rd();
        struct Node
        {
            int len;
            vector<int> cnt;
            Node()
            {
                len = 0;
                cnt.assign(26, 0);
            }
            void input()
            {
                char c;
                while ((c = getchar()) != '\n')
                    ++cnt[c - 'a'], ++len;
            }
            bool operator<(const Node &_) const
            {
                return len < _.len;
            }
        };
        vector<Node> N(n + 1);
        for (int i = 1; i <= n; ++i)
            N[i].input();
        priority_queue<Node> Q;
        Q.push(N[n]);
        auto Erase = [&](Node A, Node B)
        {
            Node T;
            T.len = A.len % B.len;
            int t = A.len / B.len;
            for (int i = 0; i < 26; ++i)
            {
                T.cnt[i] = A.cnt[i] - B.cnt[i] * t;
                if (T.cnt[i] < 0)
                {
                    T.len = -1;
                    break;
                }
            }
            return T;
        };
        for (int i = n - 1; i >= 1; --i)
        {
            while (!Q.empty() && Q.top().len >= N[i].len)
            {
                auto T = Erase(Q.top(), N[i]);
                if (T.len == -1)
                    End("NO");
                Q.pop();
                Q.push(T);
            }
            Q.push(N[i]);
        }
        vector<Node> ans;
        while (!Q.empty())
            ans.push_back(Q.top()), Q.pop();
        reverse(ans.begin(), ans.end());
        for (int i = 1; i < ans.size(); ++i)
        {
            auto A = ans[i].cnt, B = ans[i - 1].cnt;
            for (int j = 0; j < 26; ++j)
                if (A[j] < B[j])
                    End("NO");
        }
        puts("YES");
        vector<int> now(26);
        string s;
        for (auto [l, A] : ans)
            for (int i = 0; i < 26; ++i)
                while (now[i] < A[i])
                    s += 'a' + i, ++now[i];
        for (int i = 1; i <= n; ++i)
        {
            string t;
            for (int j = 0; j < N[i].len; ++j)
                t += s[j % s.size()];
            cout << t << '\n';
            s = t;
        }
    }
}
bool Ri;
int main()
{
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
