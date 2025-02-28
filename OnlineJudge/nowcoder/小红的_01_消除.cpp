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
        string s;
        int n;
        cin >> n;
        cin >> s;
        int x = rd(), y = rd(), z = rd();
        int i = 0;
        while (i < n && s[i] == '1')
            ++i;
        if (i == n)
            End(0);
        vector<int>cnt;
        while (i < n)
        {
            if (i == 0 || s[i] != s[i - 1])
                cnt.push_back(0);
            ++cnt[cnt.size() - 1];
            ++i;
        }
        ll ans = 0;
        for (int j = 0; j + 1 < cnt.size(); j += 2)
            ans += min(cnt[j], cnt[j + 1]);
        cout << min(ans, 0ll + y) << '\n';
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
