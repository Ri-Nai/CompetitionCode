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
        vector<int> A(n + 1), B(n);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
            // A.push_back(rd());
        for (int i = 1; i < n; ++i)
            // B.push_back(rd());
            B[i] = rd();
        sort(A.begin() + 1, A.end());
        sort(B.begin() + 1, B.end());
        vector<int> canLeft(n + 1), canRight(n + 1);
        canLeft[0] = canRight[n] = 1;
        for (int i = 1; i < n; ++i)
            canLeft[i] = canLeft[i - 1] && A[i] <= B[i];
        for (int i = n - 1; i >= 1; --i)
            canRight[i] = canRight[i + 1] && A[i + 1] <= B[i];
        for (int i = 0; i <= n - 1; ++i)
        {
            if (canLeft[i] && canRight[i + 1])
                End(A[i + 1]);
        }
        End(-1);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
