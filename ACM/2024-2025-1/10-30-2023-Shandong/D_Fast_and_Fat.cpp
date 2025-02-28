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
        int n;
        scanf("%d", &n);
        struct Player
        {
            int v, w;
            void input()
            {
                scanf("%d%d", &v, &w);
            }
        };
        vector<Player> P(n);
        for (int i = 0; i < n; ++i)
            P[i].input();
        int l = 1, r = 1e9, ans;
        auto check = [&](int limit)
        {
            priority_queue<int> upper;
            priority_queue<int> lower;
            for (int i = 0; i < n; ++i)
            {
                if (P[i].v >= limit)
                    upper.push(P[i].v + P[i].w);
                else
                    lower.push(P[i].w);
            }
            while (!lower.empty() && !upper.empty())
            {
                int u = upper.top();
                int v = lower.top();
                upper.pop();
                lower.pop();
                if (u - v < limit)
                    return false;
            }
            return lower.empty();
        };
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << ans << endl;
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
