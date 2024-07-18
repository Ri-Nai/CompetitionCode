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
        int n = rd();
        vector<int> A;
        int lcm = 1;
        for (int i = 0; i < n; ++i)
        {
            A.push_back(rd());
            int g = gcd(lcm, A[i]);
            lcm = 1ll * lcm / g * A[i];
        }
        long long now = 0;
        for (int i = 0; i < n; ++i)
            now += lcm / A[i];
        if (now >= lcm)
        {
            cout << "-1\n";
            return;
        }
        for (int i = 0; i < n; ++i)
            cout << lcm / A[i] << " \n"[i == n - 1];
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
