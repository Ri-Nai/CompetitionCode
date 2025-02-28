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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        vector<ll> suf(n + 2);
        for (int i = n; i >= 1; --i)
            suf[i] = a[i] + suf[i + 1];
        vector<ll> ans;
        ans.push_back(suf[1]);
        priority_queue<ll> Q;
        for (int i = 2; i <= n; ++i)
            Q.push(suf[i]);
        for (int i = 2; i <= n; ++i)
        {
            ans.push_back(ans.back() + Q.top());
            Q.pop();
        }
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " \n"[i == ans.size() - 1];
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
