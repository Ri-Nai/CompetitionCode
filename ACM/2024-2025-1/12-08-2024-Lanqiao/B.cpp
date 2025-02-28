#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    long long ans = 0;
    for (int k = 1; k <= n; ++k)
    {
        // vector<pair<int, int>> gcds;
        vector<int> gcds(n);
        for (int i = 1; i <= n; ++i)
            gcds[i - 1] = gcd(a[i], a[k]);
        sort(gcds.begin(), gcds.end());
        for (int i = 0; i < n; ++i)
            ans += gcds[i] * 1ll * (2 * i + 1);
    }
    cout << ans << endl;
}
/*
3 5 3 5 3

*/
