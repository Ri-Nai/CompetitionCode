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
        int n = rd(), k = rd(), mod = rd();
        vector<int> has(1, 0);
        vector<int> dp(1 << 16), last(1 << 16);
        vector<int> mark(1 << 16);
        dp[0] = 1, mark[0] = 1;
        auto Add = [&](int &x, int y)
        {
            x += y;
            if (x >= mod)
                x -= mod;
        };
        auto show = [&](int x)
        {
            for (int i = 0; i < k; ++i)
            {
                putchar(x % 3 + 'A');
                x /= 3;
            }
        };
        for (int i = 1; i <= n; ++i)
        {
            auto read = [&]()
            {
                char s[15];
                scanf("%s", s);
                vector<int> res(k);
                for (int i = 0; i < k; ++i)
                    if (s[i] == '+')
                        res[i] = 1;
                    else if (s[i] == '-')
                        res[i] = 2;
                return res;
            };
            auto tag = read();
            for (auto x : has)
                last[x] = dp[x];
            vector<int> New;
            for (auto x : has)
            {
                int now = 0;
                int t = 1;
                int q = x;
                for (int j = 0; j < k; ++j)
                {
                    int p = (x + tag[j]) % 3;
                    x /= 3;
                    now += p * t;
                    t = t + t + t;
                }
                if (!mark[now])
                    mark[now] = 1, New.push_back(now);
                Add(dp[now], last[q]);
            }
            has.insert(has.end(), New.begin(), New.end());
        }
        sort(has.begin(), has.end(),
        [&](int x, int y)
        {
            for (int i = 0; i < k; ++i)
            {
                int a = x % 3;
                int b = y % 3;
                if (a != b)
                    return a < b;
                x /= 3, y /= 3;
            }
            return x < y;
        });
        for (auto x : has)
        {
            show(x);
            printf(" %d\n",dp[x]);
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t; cin >> t; while(t--)
    T::solve();
}
