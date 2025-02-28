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
        int n = rd(), k = rd();
        priority_queue<int>Q;
        for (int i = 1; i <= n; ++i)
            Q.push(rd());
        int now = 0;
        int last = 0;
        vector<ll> res(2);
        while (!Q.empty())
        {
            int u = Q.top();
            Q.pop();
            if (now == 1)
            {
                int p = min(k, last - u);
                u += p;
                k -= p;
            }
            else last = u;
            res[now] += u;
            now ^= 1;
        }
        cout << res[0] - res[1] << '\n';
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
