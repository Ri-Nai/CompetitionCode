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
        cin >> n;
        vector<int> c(n + 1);

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            ++c[x];
        }
        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
        while (c.back() == 0)
            c.pop_back();
        int m = c.size();
        map<int, int> mp;
        int now = 0;
        int res = 0;
        vector<int> has(m);
        vector<int> has2(m);
        while (true)
        {
            bool flag = 1;
            now ^= 1;
            pair<int, int> ans = {n + 1, -1};
            for (int i = 0; i < m; ++i)
            {
                if (!c[i])
                    continue;
                flag = 0;
                if (c[i] & 1)
                    ans = min(ans, make_pair(c[i], i));
            }
            if (flag)
                break;
            if (ans.second == -1)
                for (int i = 0; i < m; ++i)
                {
                    if (!c[i])
                        continue;
                    ans = min(ans, make_pair(c[i], i));
                }
            if (now) 
            {
                if (!has[ans.second])
                {
                    // cout << ans.second << " " << res << endl;
                    ++res;
                }
                has[ans.second] = 1;
            }
            else 
                has2[ans.second] = 1;
            // cout << ans.second << endl;
            --c[ans.second];
            if (now && !c[ans.second] && !has2[ans.second])
                ++res;
        }
        cout << res << "\n";
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
