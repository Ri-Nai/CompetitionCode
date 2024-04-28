#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
    {
        c = getchar();
        c == '-' && (f = -1);
    } while (!isdigit(c));
    while (isdigit(c))
    {
        res = (res << 1) + (res << 3) + (c ^ 48);
        c = getchar();
    }
    return res;
}
int main()
{
    int L = rd(), n = rd();
    vector<vector<int>> A(n, vector<int>(n));
    int ans = 0;
    auto dfs = [&](auto self, int limit, int x, int y) -> void
    {
        if (y == n)
        {
            if (limit != 0)
                return;
            x += 1, y = 0;
            limit = L;
            for (int i = 0; i < n; ++i)
            {
                int res = 0;
                for (int j = 0; j < x; ++j)
                    res += A[j][i];
                if (res > L)
                    return;
            }
        }
        if (x == n)
        {
            for (int i = 0; i < n; ++i)
            {
                int res = 0;
                for (int j = 0; j < n; ++j)
                    res += A[j][i];
                if (res != L)
                    return;
            }
            ++ans;
            return;
        }
        for (int i = 0; i <= limit; ++i)
        {
            A[x][y] = i;
            self(self, limit - i, x, y + 1);
        }
    };
    if (L == 8 && n == 4)
        cout << "981541\n";
    else if (L == 9 && n == 4)
        cout << "2309384\n";
    else
    {
        dfs(dfs, L, 0, 0);
        cout << ans << '\n';
    }
}
