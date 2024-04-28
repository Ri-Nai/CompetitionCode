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
        vector<string> A, B;
        for (int i = 0; i < n; ++i)
        {
            string t;
            cin >> t;
            A.push_back(t);
        }
        for (int i = 0; i < n; ++i)
        {
            string t;
            cin >> t;
            B.push_back(t);
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][j] != B[i][j])
                    cout << i + 1 << ' ' << j + 1 << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
