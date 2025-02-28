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
        int n;
        scanf("%d", &n);
        vector<vector<int>> mark(n + 1, vector<int>(n + 1, 1));
        cout << "Yes\n";
        mark[1][1] = 1;
        mark[1][2] = 2;
        mark[2][1] = 3;
        mark[2][2] = 4;
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
                mark[i][j] = mark[j][i] = i + i;
            mark[i][i] = i + i - 1;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cout << mark[i][j] << " \n"[j == n];
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
