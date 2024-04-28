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
        int n, m;
        cin >> n >> m;
        vector<int>L(2,m),R(2,-1),U(2,n),D(2,-1);
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j)
            {
                int t = s[j] == 'B';
                L[t] = min(L[t], j);
                R[t] = max(R[t], j);
                U[t] = min(U[t], i);
                D[t] = max(D[t], i);
            }
        }
        int flag = 0;
        for (int i = 0; i <= 1; ++i)
            flag |= (L[i] == 0 && U[i] == 0 && R[i] == m - 1 && D[i] == n - 1);
        cout << (flag ? "YES" : "NO") << "\n";
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
