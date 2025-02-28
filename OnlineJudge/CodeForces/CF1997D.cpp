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
        int n;
        cin >> n;
        vector<int> A(n + 1);
        vector<ll> S(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> A[i], S[i] = S[i - 1] + A[i];
        string s = ".", t;
        cin >> t;
        s += t;
        auto Solve = [&](auto self, int L, int R) -> ll
        {
            if (R <= L)
                return 0;
            while (L <= n && s[L] != 'L')
                ++L;
            while (R >= 1 && s[R] != 'R')
                --R;
            if (R <= L)
                return 0;
            // cout << L << " " << R << " "  << s << '\n';
            return S[R] - S[L - 1] + self(self, L + 1, R - 1);

        };
        cout << Solve(Solve, 1, n) << '\n';
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
