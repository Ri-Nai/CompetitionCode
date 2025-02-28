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
        int n = rd(), L = rd(), R = rd();
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = rd(), A[i] = (A[i] - 1) / 2;
        vector<int> B;
        int cnt = 0;
        if (R == n)
            End("Yes");
        for (int i = 0; i < n; ++i)
        {
            if(A[i] != 0)
                B.push_back(A[i]);
            else ++cnt;
        }
        int round = (n - L + 1) / (R - L);
        ll sum = 0;
        for (int x : B)
        {
            if (x > round)
                x = round;
            sum += x;
        }
        if (sum >= 1ll * round * L)
            cout << "Yes\n";
        else cout << "No\n";
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
/*
D - h
D - hi
12 - now

*/
