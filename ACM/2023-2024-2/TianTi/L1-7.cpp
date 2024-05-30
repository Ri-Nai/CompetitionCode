#include <bits/stdc++.h>
using namespace std;
int ans(int x)
{
    if (x < 10)
        return 0;
    int t = 1;
    while (x)
        t *= x % 10, x /= 10;
    return ans(t) + 1;
}
int main()
{
    // ios::sync_with_stdio(0);
    int l, r;
    cin >> l >> r;
    int mx = 0;
    vector<int> res;
    for (int i = l; i <= r; ++i)
    {
        int t = ans(i);
        if (t > mx)
        {
            mx = t;
            res.clear();
        }
        if (t == mx)
            res.push_back(i);
    }
    cout << mx << '\n';
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " \n"[i == res.size() - 1];
}
