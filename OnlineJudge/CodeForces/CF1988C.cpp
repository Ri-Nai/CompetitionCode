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
        long long n;
        cin >> n;
        vector<long long> ans;
        for (int i = 63; i >= 0; --i)
            if (1ll << i & n)
                if ((1ll << i) != n)
                    ans.push_back(n ^ (1ll << i));
        ans.push_back(n);
        int m = ans.size();
        cout << m << '\n';
        for (int i = 0; i < m; ++i)
            cout << ans[i] << " \n"[i == m - 1];
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
/*
111
110
101
011

1111
1110
1101
1011
0111
*/
