#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
        c == '-' && (f = -1), c = getchar();
    while (isdigit(c))
        res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res * f;
}
int main()
{
    int n, B;
    scanf("%d%d", &n, &B);
    vector<int> P(n + 1), S(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &P[i], &S[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        priority_queue<int, vector<int>, greater<int>>Q;
        for (int j = 1; j <= n; ++j)
            if (j != i)
                Q.push(S[j] + P[j]);
        Q.push(S[i] + P[i] / 2);
        int res = 0;
        int T = B;
        while (!Q.empty())
        {
            int u = Q.top();
            Q.pop();
            if (u > T)
                break;
            ++res;
            T -= u;
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}
