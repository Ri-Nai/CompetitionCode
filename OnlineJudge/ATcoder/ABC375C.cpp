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
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i)
            cin >> grid[i];
        auto ans = grid;
        for (int cnt = 1; cnt < 4; ++cnt)
        {
            grid = ans;
            for (int i = 0; i < n / 2; ++i)
            {
                if ((i + 1 & 3) < cnt)
                    continue;
                auto work = [&](int x, int y)
                {
                    ans[y][n - x - 1] = grid[x][y];
                };
                for (int j = i; j < n - i; ++j)
                    work(i, j), work(n - i - 1, j), work(j, n - i - 1), work(j, i);
            }
        }
        for (int i = 0; i < n; ++i)
            cout << ans[i] << '\n';
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
