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
        vector<int> A(n + 1), B(n + 1);
        vector<int> idB(n + 1), idA(n + 1);
        for (int i = 1; i <= n; ++i)
            idA[A[i] = rd()] = i;
        for (int i = 1; i <= n; ++i)
            idB[B[i] = rd()] = i;
        int l1 = 1, r1 = n, l2 = 1, r2 = n;
        auto dis = [&](int x, int l, int r)
        {
            if (x < l || x > r)
                return -1;
            return min(abs(x - l), abs(r - x));
        };
        while (l1 < r1)
        {
            if (dis(idB[A[l1]], l2, r2) > dis(idB[A[r1]], l2, r2))
                ++l1;
            else --r1;
            if (dis(idA[B[l2]], l1, r1) < dis(idA[B[r2]], l1, r1))
                ++l2;
            else --r2;
        }
        if (A[l1] == B[l2])
            cout << "Bob" << '\n';
        else End("Alice");
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
