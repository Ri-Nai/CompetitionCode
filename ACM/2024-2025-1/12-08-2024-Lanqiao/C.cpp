#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += max(0, a[i] - i - 1);
    cout << ans << endl;

}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
