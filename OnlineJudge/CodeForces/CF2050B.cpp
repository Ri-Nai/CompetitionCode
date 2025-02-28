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
        vector<vector<int>> a(2);
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            a[i & 1].push_back(x);
        }
        vector<long long> now(2);
        for (int i : {0, 1})
        {
            long long sum = accumulate(a[i].begin(), a[i].end(), 0ll);
            if (sum % a[i].size() != 0)
                End("NO");
            now[i] = sum / a[i].size();
        }
        if (now[0] != now[1])
            End("NO");
        End("YES");
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
