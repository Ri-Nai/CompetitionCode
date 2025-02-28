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
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = rd();
        int mn = 1e9 + 5;
        sort(A.begin(), A.end());
        auto it = unique(A.begin(), A.end());
        A.erase(it, A.end());
        n = A.size();
        if (n == 1)
        {
            cout << 1 << '\n' << A[0] << '\n';
            return;
        }
        for (int i = 1; i < n; ++i)
            mn = min(A[i] - A[i - 1], mn);
        if (mn & 1)
            End("-1");
        vector<int> res;
        bool flag = 0;
        for (int t = 1; t <= 42; ++t)
        {
            int mx = 0, mn = 1e9 + 5;
            vector<int> B;
            for (int i = 0; i < n; ++i)
                mx = max(A[i], mx), mn = min(A[i], mn);
            if (mx == 0)
            {
                flag = 1;
                break;
            }
            res.push_back(mn + mx >> 1);
            for (int i = 0; i < n; ++i)
                B.push_back(abs(A[i] - (mn + mx >> 1)));
            A = B;
        }
        if (flag && res.size() <= 40)
        {
            cout << res.size() << '\n';
            for (int x : res)
                cout << x << ' ';
            cout << '\n';
        }
        else End("-1");
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
/*
*/
