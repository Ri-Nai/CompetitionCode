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
        string s;
        cin >> s;
        int n = s.size();
        int cnt3 = 0;
        int last = -1;
        vector<int> has(5);
        auto get = [&](char c) -> int
        {
            if (c == 'U')
                return 3;
            return c - '3';
        };
        for (int i = 0; i < n; ++i)
        {
            if (i >= 10)
                cnt3 -= s[i - 10] == '3';
            cnt3 += s[i] == '3';

            if (i >= 90)
                --has[get(s[i - 90])];
            ++has[get(s[i])];

            if (i >= 9 && cnt3 == 10)
                End("invalid");

            if (i >= 89 && has[2] + has[3] == 0)
                End("invalid");

            if (s[i] == '5' && last == 0)
                End("invalid");

            if (s[i] == 'U')
                last = 1;

            if (s[i] == '5')
                last = 0;

        }
        End("valid");
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
