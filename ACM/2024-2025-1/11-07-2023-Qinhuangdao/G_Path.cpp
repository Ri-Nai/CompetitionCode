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
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> A(n + 1), B(m + 1);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &A[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &B[i]);
        long long ans = 0;
        for (int i = 2; i <= n; ++i)
            ans += abs(A[i] - A[i - 1]);
        for (int i = 2; i <= m; ++i)
            ans += abs(B[i] - B[i - 1]);
        cout << ans << endl;
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
