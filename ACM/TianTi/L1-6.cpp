#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(0);
    int n, m;
    cin >> n;
    vector<double> P(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> P[i];
    vector<int> cnt(n + 1);
    double ans = 0;
    int x, y;
    while ((cin >> x >> y) && x)
    {
        cnt[x] += y;
        ans += P[x] * y;
    }
    for (int i = 1; i <= n; ++i)
        cout << cnt[i] << '\n';
    printf("%.2f\n",ans);
}
