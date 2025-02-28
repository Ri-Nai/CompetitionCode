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
        vector<pair<int, int>> A;
        for (int i = 0; i < n; ++i)
        {
            int x;
            scanf("%d", &x);
            A.emplace_back(x, x - i);
        }
        sort(A.begin(), A.end(), greater<pair<int, int>>());
        map<int, int> has, val;
        long long ans = 0;
        for (auto [w, d] : A)
        {
            if (has[d])
            {
                has[d] = 0;
                if (val[d] + w > 0)
                    ans += val[d] + w;
            }
            else has[d] = 1, val[d] = w;
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
