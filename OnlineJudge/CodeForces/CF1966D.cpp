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
        int mx = 0;
        for (int j = 25; j >= 0; --j)
            if (1 << j & k)
            {
                mx = j;
                break;
            }
        vector<int> ans;
        int now = 0;
        if ((1 << mx) == k)
            ans.push_back((3 << mx));
        for (int i = 0; i < mx; ++i)
            ans.push_back(1 << i), now |= 1 << i;
        if (k - now - 1 != 0)
            ans.push_back(k - now - 1);
        ans.push_back(k + 1);
        ans.push_back(k + 2);
        ans.push_back(k + 3);
        for (int i = mx + 1; (1 << i) <= n; ++i)
            ans.push_back(1 << i);
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int x : ans)
            cout << x << ' ';
        cout << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
