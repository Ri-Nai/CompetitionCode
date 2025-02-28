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
        vector<int> a(n + 1);
        vector<int> b(n + 1);
        iota(b.begin(), b.end(), 0);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        vector<pair<int, int>> ans;
        while (a != b)
        {
            int mxp = 0;
            for (int i = 1; !mxp && i <= n; ++i)
                if (i != a[i])
                    mxp = i;
            for (int i = n; i > mxp; --i)
            {
                if (a[i] < a[mxp])
                {

                // cout << mxp << ' ' << i << '\n';
                // for (int j = 1; j <= n; ++j)
                //     cout << a[j] << ' ';
                // cout << '\n';
                    ans.emplace_back(mxp, i);
                    sort(a.begin() + mxp, a.begin() + i + 1);
                    break;
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto [u, v] : ans)
            cout << u << ' ' << v << '\n';
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
