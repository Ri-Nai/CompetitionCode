#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (i = j; i <= k; ++i)
#define dow(i, j, k) for (i = j; i >= k; --i)
#define pr pair
#define mkp make_pair
#define fi first
#define se second
const int N = 2e5 + 10;
#define LL long long
char s[N];
int n, a[N], suf[N], pre[N];
int main()
{
    // freopen("in.txt","r",stdin);
    scanf("%d", &n);
    int i, j;
    scanf("%s", s + 1);
    rep(i, 1, n)
    {
        if (s[i] == '(')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1] - 1;
    }
    rep(i, 1, n) pre[i] = max(pre[i - 1], a[i]);
    dow(i, n - 1, 0) suf[i] = min(suf[i + 1], a[i]);
    suf[n] = a[n];
    rep(i, 0, n)
    {
        int mn = 1 << 30;
        mn = min(mn, suf[i] - a[i]);
        if (i)
            mn = min(mn, a[i] - pre[i] + a[n] - a[i]);
        // cerr<<i<<' '<<mn<<'\n';
        mn = -mn;
        int sum = a[n];
        assert((2 * (mn + 1 >> 1) + sum) % 2 == 0);
        if (mn >= 0)
            cout << (mn + 1) / 2 + (2 * (mn + 1 >> 1) + sum) / 2 << '\n';
        else
            cout << (2 * (mn + 1 >> 1) + sum) / 2 << '\n';
    }
}
