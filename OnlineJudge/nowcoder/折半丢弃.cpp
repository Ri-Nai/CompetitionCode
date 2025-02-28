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
        vector<int> cnt(n);
        for (int i = 1; i <= n; ++i)
        {
            int x = rd();
            while (x >= n)
                x >>= 1;
            ++cnt[x];
        }
        for (int i = n - 1; i >= 0; --i)
            if (cnt[i] > 1)
                cnt[i >> 1] += cnt[i] - 1, cnt[i] = 1;
        vector<set<int>> S(n + 1);
        for (int i = 1; i < n; ++i)
        {
            if (!cnt[i])
                continue;
            int x = i;
            while (x)
            {
                x >>= 1;
                S[x].insert(i);
            }
        }
        for (int i = n - 1; i >= 0; --i)
            if (!cnt[i])
            {
                if (S[i].empty())
                    continue;
                auto it = S[i].end();
                --it;
                int t = *it, x = *it;
                --cnt[t];
                while (t)
                {
                    t >>= 1, S[t].erase(x);
                    S[t].insert(i);
                }
            }
        for (int i = 0; i < n; ++i)
            if (!cnt[i])
                End(i);
        End(n);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
/*
1
1 1
1 1 1 1
1 1 1 0 1 1 1 1

*/
