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
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i < n; ++i)
            printf("%d %d\n%d %d\n", i, i, i, i + 1);
        printf("%d %d\n", n, n);
        printf("%d %d\n", n, 1);
        int now = n + n;
        if (now == k)
            return;
        for (int i = 1; i <= n; ++i)
            for (int j = 1 + (i == n); j <= n; ++j)
            {
                if (i != j && i + 1 != j)
                {
                    printf("%d %d\n", i, j);
                    if (++now == k)
                        return;
                }
            }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
