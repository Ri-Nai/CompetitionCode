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
        int n, m, k, w;
        scanf("%d%d%d%d", &n, &m, &k, &w);
        vector<int> red(n);
        vector<int> black(m);
        for (int i = 0; i < n; ++i)
            scanf("%d", &red[i]);
        for (int i = 0; i < m; ++i)
            scanf("%d", &black[i]);
        black.push_back(0);
        black.push_back(w + 1);
        sort(red.begin(), red.end());
        sort(black.begin(), black.end());
        vector<int> ans;
        auto work = [&](int l, int r)
        {
            auto bg = upper_bound(red.begin(), red.end(), l);
            auto ed = upper_bound(red.begin(), red.end(), r);
            if (bg == ed)
                return 1;
            vector<int> left;
            int last = -1e9 - 1919810;
            for (auto it = bg; it < ed; ++it)
            {
                if (last + k > *it)
                    continue;
                left.push_back(*it);
                last = *it;
            }
            int right = r;
            int idx = left.size() - 1;
            while (idx >= 0 && left[idx] + k > right)
            {
                left[idx] = right - k;
                right = left[idx--];
            }
            if (left[0] <= l)
                return 0;
            ans.insert(ans.end(), left.begin(), left.end());
            return 1;
        };
        for (int i = 1; i <= m + 1; ++i)
            if (!work(black[i - 1], black[i]))
            {
                puts("-1");
                return;
            }
        cout << ans.size() << "\n";
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
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
