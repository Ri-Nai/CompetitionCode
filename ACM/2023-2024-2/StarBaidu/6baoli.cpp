#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    vector<int> cnt(n + 1, 0);
    cnt[0] = n;
    int m = 0;
    while (1)
    {
        int p = -1;
        for (int j = 0; j <= m; ++j)
            if (cnt[j] == 0)
                break;
            else
                p = j;
        if (p == -1)
            break;
        for (int j = 0; j <= p; ++j)
            --cnt[j];
        cnt[p + 1] += p + 1;
        m = max(m, p + 1);
    }
    for (int i = 0; i <= m; ++i)
        if (cnt[i])
            cout << i << ' ' << cnt[i] << '\n';
}
int main()
{
    solve(7);
}
