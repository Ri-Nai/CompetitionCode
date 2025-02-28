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
        vector<int> A(3);
        for (int i = 0; i < 3; ++i)
            A[i] = rd();
        int ok = 0;
        int can = 1;
        while (can)
        {
            int flag = 1;
            for (int &x : A)
            {
                flag &= ((x & 1) == 1);
                x >>= 1;
                if (!x)
                    can = 0;
            }
            ok |= flag;
            if (ok)
                break;
        }
        if (ok)
            End("NO");
        else End("YES");
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
