#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int x, y, K;
    int num = 0, ans = 0;
    scanf("%d%d%d", &x, &y, &K);
    if (x > y)
        return K;
    for (int i = 1; i <= K; ++i)
    {
        if (num + 9 * x - 11 * y < 0)
            num += 11 * x;
        else
        {
            num += 9 * x;
            num -= 11 * y;
            ++ans;
        }
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        printf("Case #%d: %d\n", i, solve());
    }
}
