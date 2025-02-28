#include <bits/stdc++.h>
using namespace std;
int rand_range(int l, int r)
{
    return 1ll * rand() * rand() % (r - l + 1) + l;
}
int main()
{
    // freopen("1.in", "w", stdout);
    srand(time(0));
    // int n = 2e5, q = 2e5;
    int T = 1;
    cout << T << '\n';
    while (T--)
    {
        int n = rand_range(2, 100), k = rand_range(3, 100);
        cout << n << ' ' << k << '\n';
        for (int i = 1; i <= n; ++i)
            cout << rand_range(1, 500) << ' ' << rand_range(1, 500) << '\n';
    }
}
