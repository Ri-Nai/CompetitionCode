#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
int stk[N], top;
int a[N], l[N], r[N];
int ans[N], f[N];
int mn[N];
int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    for (int i = 1; i <= n; ++i)
        a[i] = (a[i - 1] * 1ll * x + y) % z;
    a[0] = a[n + 1] = 1e9 + 5;
    for (int i = 0; i <= n + 1; ++i)
    {
        while (top && a[stk[top]] < a[i])
        {
            r[stk[top]] = i;
            --top;
        }
        l[i] = stk[top];
        stk[++top] = i;
    }
    memset(ans, 0x7f, sizeof ans);
    for (int i = 1; i <= n; ++i)
    {
        int x = r[i] - l[i] - 1;
        ans[x] = min(ans[x], a[i]);
    }
    for (int i = n; i >= 1; --i)
        ans[i] = min(ans[i], ans[i + 1]);
    // for (int i = 1; i <= n; ++i)
    //     cout << ans[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i)
        f[i] = (1ll * x * f[i - 1] + ans[i] + y) % z;
    cout << f[n] << endl;
}
/*
3 5 3 5 3

*/
