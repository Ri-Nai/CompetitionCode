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
        long long k;
        cin >> n >> k;
        if ((1ll << min(n - 1, 60)) < k)
            End(-1);
        vector<int> backs, fronts;
        for (int i = 1; i <= n; ++i)
        {
            if ((1ll << min(n - i - 1, 60)) < k)
            {
                k -= (1ll << min(n - i - 1, 60));
                backs.push_back(i);
            }
            else
            {
                fronts.push_back(i);
            }
        }
        for (int x : fronts)
            cout << x << ' ';
        for (int i = backs.size() - 1; i >= 0; --i)
            cout << backs[i] << ' ';
        cout << '\n';
        //  for (int i = 1; i <= 
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
