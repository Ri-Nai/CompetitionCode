#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> c(n + 1), l(n + 1);
    map<int, int> last, now;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        l[i] = last[c[i]];
        last[c[i]] = i;
    }
    int ans = 0;
    for (int i = 1, j = 0; i <= n; ++i)
    {
        while ((j + 1) <= n && l[j + 1] < i)
            ++j;
        ans = max(j - i + 1, ans);
    }
    cout << ans << endl;
}
