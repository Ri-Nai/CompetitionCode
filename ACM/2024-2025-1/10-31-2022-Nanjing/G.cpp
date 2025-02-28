#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    int sz = 1, can = 0;
    int total = 1;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] == -1)
        {
            if (sz == 1)
            {
                if (can == 0)
                {
                    cout << -1 << '\n';
                    return ;
                }
                --can;
                ++total;
                ++sz;
            }
            else --sz;
        }
        else if (A[i] == 0)
        {
            if (sz == 1)
                ++sz, ++total;
            else --sz, ++can;
        }
        else ++sz, ++total;
    }
    cout << total / gcd(total, sz) << " " << sz / gcd(total, sz) << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}
