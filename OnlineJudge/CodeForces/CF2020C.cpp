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
        ll b, c, d;
        cin >> b >> c >> d;
        ll a = 0;
        bool valid = true;

        for (int i = 0; i < 60; ++i)
        {
            ll d_i = (d >> i) & 1;
            ll c_i = (c >> i) & 1;
            ll b_i = (b >> i) & 1;

            if (d_i == 1)
            {
                if (c_i != 1)
                    a |= (1ll << i);
                else if (!b_i)
                    End(-1);
            }
            else
            {
                if (b_i == 1 && c_i == 0)
                    End(-1);
                if (b_i == 1 && c_i == 1)
                    a |= (1ll << i);
            }
        }
        cout << a << '\n';
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
