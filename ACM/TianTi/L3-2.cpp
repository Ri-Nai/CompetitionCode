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
    int T = rd();
    while (T--)
    {
        int n = rd(), m = rd(), k = rd();
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i)
        {
            int now = 0, rest = k;
            long long res = 0;
            if (s[i] == '0' && m)
                ++now, --rest;
            else if (s[i] == '1') --rest;
            for (int j = 1; rest > 0 && (i - j >= 0 || i + j < n); ++j)
            {
                auto check = [&](int p)
                {
                    if (p < 0 || p >= n)
                        return;
                    if (rest <= 0)
                        return;
                    if (s[p] == '0' && now < m)
                        ++now, --rest, res += j;
                    else if (s[p] == '1')
                        --rest, res += j;
                };
                check(i + j);
                check(i - j);
            }
            cout << res << " \n"[i == n - 1];
        }
    }
}
