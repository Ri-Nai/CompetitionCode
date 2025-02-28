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
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = s[i] - 48;
        int sum = accumulate(a.begin(), a.end(), 0);
        sum %= 9;
        int cnt2 = count(a.begin(), a.end(), 2);
        int cnt3 = count(a.begin(), a.end(), 3);
        for (int i = 0; i <= min(cnt2, 9); ++i)
            for (int j = 0; j <= min(cnt3, 3); ++j)
                if ((sum + i * 2 + 6 * j) % 9 == 0)
                    End("YES");
        End("NO");
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
