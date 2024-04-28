#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int M = 1e6 + 5, mod = 1e9 + 7;
vector<int> P(M);
vector<int> ans(M);
vector<int> dif(M);
namespace T
{
    void solve()
    {
        int n = rd();
        cout << ans[n] << '\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    auto Add = [&](int &x, int y)
    {
        if (y < 0)
            y += mod;
        x += y;
        if (x > mod)
            x -= mod;
    };
    int A = sqrt(M);
    for (int i = 2; i < M; ++i)
        if (!P[i])
        {
            int now = i - 1;
            Add(dif[i], now);
            for (int j = i + i; j < M; j += i)
            {
                P[j] = 1;
                Add(dif[j], (now + i - 1) % i - now);
                now = (now + i - 1) % i;
            }
        }
    for (int i = 4; i + 4 < M; i += 8)
        Add(dif[i], 2), Add(dif[i + 4], -2);
    int now = 0;
    for (int i = 1; i < M; ++i)
    {
        Add(now, dif[i]);
        ans[i] = ans[i - 1];
        Add(ans[i], now);
    }
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
