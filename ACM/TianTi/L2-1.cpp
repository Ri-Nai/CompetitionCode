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
    int n = rd(), m = rd();
    vector<vector<int>> A(n);
    for (int i = 0; i < n; ++i)
    {
        int t = rd();
        while (t--)
            A[i].push_back(rd());
        sort(A[i].begin(), A[i].end());
    }
    m = rd();
    while (m--)
    {
        int x = rd(), y = rd();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            auto Find = [&](vector<int> A, int x) -> int
            {
                auto t = lower_bound(A.begin(), A.end(), x);
                if (t == A.end())
                    return 0;
                return *t == x;
            };
            if (Find(A[i], x) && Find(A[i], y))
                res += 1;
        }
        printf("%d\n", res);
    }
}
